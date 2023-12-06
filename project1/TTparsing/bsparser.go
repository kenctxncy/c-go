package main

import (
	"context"
	"fmt"
	"net/url"
	"time"

	"github.com/tealeg/xlsx"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

func checkErr(err error) {
	if err != nil {
		panic(err)
	}
}

type Schedule struct {
	GroupId string     `bson:"group_name"`
	Weeks   WeekSlices `bson:"weeks"`
}

type ScheduleItem struct {
	Day        string `bson:"day"`
	LessonType string `bson:"lesson_type"`
	Subject    string `bson:"subject"`
	Teacher    string `bson:"teacher"`
	Room       string `bson:"room"`
	Comment    string `bson:"comment"`
}

type WeekSlices struct {
	OddWk  []ScheduleItem `bson:"odd_week"`
	EvenWk []ScheduleItem `bson:"even_week"`
}

func main() {
	serverAPI := options.ServerAPI(options.ServerAPIVersion1)
	opts := options.Client().ApplyURI(url.QueryEscape("mongodb+srv://admin:9af0m3B7KyRdYdyR@endlesssuffering.skte9xw.mongodb.net/?retryWrites=true&w=majority")).SetServerAPIOptions(serverAPI)

	fmt.Println("Pinged your deployment. You successfully connected to MongoDB!")

	// Parsing starts
	ExcelBS, err := xlsx.OpenFile("TTresources/cfuvtable.xlsx")
	checkErr(err)

	sched := Schedule{}

	groupnameCell := ExcelBS.Sheets[0].Row(0).Cells[0]
	sched.GroupId = groupnameCell.String()

	oddweeks := []ScheduleItem{}
	oddweeksStart := 4
	oddweeksEnd := 16
	for row := oddweeksStart; row <= oddweeksEnd; row++ {
		dayCell := ExcelBS.Sheets[0].Row(row).Cells[1]
		lessontypeCell := ExcelBS.Sheets[0].Row(row).Cells[2]
		subjectCell := ExcelBS.Sheets[0].Row(row).Cells[3]
		teacherCell := ExcelBS.Sheets[0].Row(row).Cells[4]
		roomCell := ExcelBS.Sheets[0].Row(row).Cells[5]
		commentCell := ExcelBS.Sheets[0].Row(row).Cells[6]

		item := ScheduleItem{
			Day:        dayCell.String(),
			LessonType: lessontypeCell.String(),
			Subject:    subjectCell.String(),
			Teacher:    teacherCell.String(),
			Room:       roomCell.String(),
			Comment:    commentCell.String(),
		}
		oddweeks = append(oddweeks, item)
	}

	evenweeks := []ScheduleItem{}
	evenweeksStart := 18
	evenweeksEnd := 30
	for row := evenweeksStart; row <= evenweeksEnd; row++ {
		dayCell := ExcelBS.Sheets[0].Row(row).Cells[1]
		lessontypeCell := ExcelBS.Sheets[0].Row(row).Cells[2]
		subjectCell := ExcelBS.Sheets[0].Row(row).Cells[3]
		teacherCell := ExcelBS.Sheets[0].Row(row).Cells[4]
		roomCell := ExcelBS.Sheets[0].Row(row).Cells[5]
		commentCell := ExcelBS.Sheets[0].Row(row).Cells[6]

		item := ScheduleItem{
			Day:        dayCell.String(),
			LessonType: lessontypeCell.String(),
			Subject:    subjectCell.String(),
			Teacher:    teacherCell.String(),
			Room:       roomCell.String(),
			Comment:    commentCell.String(),
		}
		evenweeks = append(evenweeks, item)
	}

	sched.Weeks = WeekSlices{
		OddWk:  oddweeks,
		EvenWk: evenweeks,
	}
	// Parsing ends here

	// Saving to MongoDB
	client, err := mongo.Connect(context.Background(), opts)
	checkErr(err)

	ctx, cancel := context.WithTimeout(context.Background(), 10*time.Second)
	defer cancel()

	collection := client.Database("endlesssuffering").Collection("schedule")

	// Saving
	_, err = collection.InsertOne(ctx, sched)
	checkErr(err)

	// Disconnect
	err = client.Disconnect(ctx)
	if err != nil {
		fmt.Println("Error disconnecting from MongoDB:", err)
	}
}
