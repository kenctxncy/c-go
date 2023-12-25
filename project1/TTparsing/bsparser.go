package main

import (
	"context"
	"encoding/json"
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

// the schedule (already in bd) (+ mozhno reraitnut cherez zapros)
/*func handleSchedule(w http.ResponseWriter, r *http.Request) {
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
		_, err = collection.InsertOne(context.TODO(), schedule)
		checkErr(err)
	}

	// Disconnect
	err = client.Disconnect(context.TODO())
	checkErr(err)
}*/

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

func main() {
	/*	http.HandleFunc("/api/schedule", handleSchedule)*/
	http.HandleFunc("/api/getSchedule", getSchedule)
	http.ListenAndServe(":8080", nil)
}
