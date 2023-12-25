package main

import (
	"context"
	"encoding/json"
	"fmt"
	"github.com/golang-jwt/jwt/v5"
	"github.com/xuri/excelize/v2"
	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
	"net/http"
)

/*
I am really exhausted of if err!=nil{}///////////////////////
*/
func checkErr(err error) {
	if err != nil {
		panic(err)
	}
}

// schedule parsing struct
type Schedule struct {
	Group   string
	Week    string
	Day     string
	Lessons []Lesson
}

// lesson tt parsing struct
type Lesson struct {
	Number  string
	Type    string
	Name    string
	Teacher string
	Room    string
	Comment string
}

// querystruct
type UpdateCommentInput struct {
	Group   string
	Week    string
	Day     string
	Number  string
	Comment string
}

const mySigningKey = "POMOGITE33333333333333"

func isAuthorized(endpoint func(http.ResponseWriter, *http.Request)) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {

		if r.Header["Token"] != nil {

			token, err := jwt.Parse(r.Header["Token"][0], func(token *jwt.Token) (interface{}, error) {
				if _, ok := token.Method.(*jwt.SigningMethodHMAC); !ok {
					return nil, fmt.Errorf("Error")
				}
				return []byte(mySigningKey), nil
			})
			checkErr(err)

			if token.Valid {
				endpoint(w, r)
			}
		} else {
			fmt.Fprintf(w, "Not Authorized")
		}
	})
}

func testEndpoint(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Ping pong")
}

// the schedule (already in bd) (+ mozhno reraitnut cherez zapros)
func handleSchedule(w http.ResponseWriter, r *http.Request) {
	serverAPI := options.ServerAPI(options.ServerAPIVersion1)
	opts := options.Client().ApplyURI("mongodb+srv://admin:9af0m3B7KyRdYdyR@endlesssuffering.skte9xw.mongodb.net/?retryWrites=true&w=majority").SetServerAPIOptions(serverAPI)

	client, err := mongo.Connect(context.TODO(), opts)
	checkErr(err)

	// Parsing starts
	ExcelBS, err := excelize.OpenFile("TTresources/cfuvtable1.xlsx")
	checkErr(err)

	cols, err := ExcelBS.GetCols("course1")
	checkErr(err)
	//connection

	collection := client.Database("endlesssuffering").Collection("schedules")

	var schedule Schedule

	for _, col := range cols {
		lessons := []Lesson{}
		for i := 3; i <= 39; i += 6 {
			lessons = append(lessons, Lesson{
				Number:  col[i],
				Type:    col[i+1],
				Name:    col[i+2],
				Teacher: col[i+3],
				Room:    col[i+4],
				Comment: col[i+5],
			})
		}
		schedule = Schedule{
			Group:   col[0],
			Week:    col[1],
			Day:     col[2],
			Lessons: lessons,
		}

		// Parsing ends here
		// Saving
		filter := bson.M{"group": schedule.Group, "week": schedule.Week, "day": schedule.Day}
		_, err = collection.ReplaceOne(context.TODO(), filter, schedule)
		checkErr(err)
	}

	// Disconnect
	err = client.Disconnect(context.TODO())
	checkErr(err)
}

// http queries moment
func getSchedule(w http.ResponseWriter, r *http.Request) {
	serverAPI := options.ServerAPI(options.ServerAPIVersion1)
	opts := options.Client().ApplyURI("mongodb+srv://admin:9af0m3B7KyRdYdyR@endlesssuffering.skte9xw.mongodb.net/?retryWrites=true&w=majority").SetServerAPIOptions(serverAPI)
	client, err := mongo.Connect(context.TODO(), opts)
	checkErr(err)

	group := r.URL.Query().Get("group")
	week := r.URL.Query().Get("week")
	day := r.URL.Query().Get("day")

	collection := client.Database("endlesssuffering").Collection("schedules")

	var schedule Schedule
	err = collection.FindOne(context.TODO(), bson.M{
		"group": group,
		"week":  week,
		"day":   day,
	}).Decode(&schedule)
	checkErr(err)

	// converting to JSON because BYTES((((
	schedJSON, err := json.Marshal(schedule)
	checkErr(err)

	//finally after all of this embarrassing suffering guys we have made the impossible............ we got the schedule uploaded.........
	w.Header().Set("Content-Type", "application/json")
	w.Write(schedJSON)

	// disconnect (top 10 gone wrong moments)
	err = client.Disconnect(context.TODO())
	checkErr(err)
}

func updateComment(w http.ResponseWriter, r *http.Request) {
	serverAPI := options.ServerAPI(options.ServerAPIVersion1)
	opts := options.Client().ApplyURI("mongodb+srv://admin:9af0m3B7KyRdYdyR@endlesssuffering.skte9xw.mongodb.net/?retryWrites=true&w=majority").SetServerAPIOptions(serverAPI)
	client, err := mongo.Connect(context.TODO(), opts)
	checkErr(err)

	collection := client.Database("endlesssuffering").Collection("schedules")

	var input UpdateCommentInput
	err = json.NewDecoder(r.Body).Decode(&input)
	checkErr(err)
	//onlygodknowshowthatabominationworks
	filter := bson.M{"group": input.Group, "week": input.Week, "day": input.Day}
	update := bson.M{"$set": bson.M{"lessons.$[elem].comment": input.Comment}}

	arrayFilter := options.ArrayFilters{}
	arrayFilter.Filters = append(arrayFilter.Filters, bson.M{"elem.number": input.Number})

	updateOptions := options.UpdateOptions{ArrayFilters: &arrayFilter}

	_, err = collection.UpdateOne(context.TODO(), filter, update, &updateOptions)
	checkErr(err)
}

func main() {
	http.Handle("/", isAuthorized(testEndpoint))
	http.HandleFunc("/api/schedule", handleSchedule)
	http.HandleFunc("/api/getSchedule", getSchedule)
	http.HandleFunc("/api/updateComment", updateComment)
	http.ListenAndServe(":8080", nil)
}
