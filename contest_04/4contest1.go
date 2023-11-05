package main

import (
	"encoding/json"
	"fmt"
	"os"
)

type Task struct {
	UserID    int    `json:"user_id"`
	ID        int    `json:"id"`
	Title     string `json:"title"`
	Completed bool   `json:"completed"`
}

type Project struct {
	ProjectID int    `json:"project_id"`
	Tasks     []Task `json:"tasks"`
}

func main() {
	var userID int
	var projects []Project
	completedT := 0

	fmt.Scanf("%v", &userID)

	data, err := os.ReadFile("data.json")
	if err != nil {
		panic(err)
	}

	err = json.Unmarshal(data, &projects)
	if err != nil {
		panic(err)
	}

	for _, proj := range projects {
		for _, tsks := range proj.Tasks {
			if tsks.UserID == userID && tsks.Completed {
				completedT++
			}
		}
	}
	fmt.Println(completedT)
}
