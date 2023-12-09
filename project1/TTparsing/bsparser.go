package main

import (
	"context"
	"fmt"
	"github.com/xuri/excelize/v2"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

func checkErr(err error) {
	if err != nil {
		panic(err)
	}
}

type Schedule struct {
	Group   string
	Week    string
	Day     string
	Lessons []Lesson
}

type Lesson struct {
	Number  string
	Type    string
	Name    string
	Teacher string
	Room    string
	Comment string
}

func main() {
	serverAPI := options.ServerAPI(options.ServerAPIVersion1)
	opts := options.Client().ApplyURI("mongodb+srv://admin:9af0m3B7KyRdYdyR@endlesssuffering.skte9xw.mongodb.net/?retryWrites=true&w=majority").SetServerAPIOptions(serverAPI)

	// Parsing starts
	ExcelBS, err := excelize.OpenFile("TTresources/cfuvtable1.xlsx")
	checkErr(err)

	cols, err := ExcelBS.GetCols("course1")
	checkErr(err)
	//connection
	client, err := mongo.Connect(context.TODO(), opts)
	checkErr(err)

	collection := client.Database("endlesssuffering").Collection("schedules")
	//connection
	fmt.Println("Pinged your deployment. You successfully connected to MongoDB!")
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
}
