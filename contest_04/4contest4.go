package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type person struct {
	Pclass int
	Age    int
	Sex    string
	Name   string
}

type PassengerS []person

func (a PassengerS) Len() int { return len(a) }
func (a PassengerS) Less(i, j int) bool {
	if a[i].Age == a[j].Age {
		return a[i].Name < a[j].Name
	}
	return a[i].Age < a[j].Age
}
func (a PassengerS) Swap(i, j int) { a[i], a[j] = a[j], a[i] }

func split(a string) person {
	var col int = 0
	var quotes bool = true
	var nquotes bool = false
	var buf string = ""
	var res person
	for _, i := range a {
		if i == ',' {
			if quotes || nquotes {
				if col%12 == 2 {
					if buf == "" {
						res.Pclass = -1
					} else {
						res.Pclass, _ = strconv.Atoi(buf)
					}
				} else if col%12 == 3 {
					res.Name = buf
				} else if col%12 == 4 {
					res.Sex = buf
				} else if col%12 == 5 {
					if buf == "" {
						res.Age = -1
					} else {
						res.Age, _ = strconv.Atoi(buf)
					}
				}
				buf = ""
				col += 1
			} else {
				buf += ","
			}

		} else if i == '"' && quotes {
			quotes = false
		} else if i == '"' && nquotes {
			buf = buf + "\""
			nquotes = false
		} else if i == '"' {
			nquotes = true
		} else {
			buf += string(i)
		}
	}
	return res
}

func main() {
	fileBytes, _ := os.ReadFile("train.csv")
	fileContent := string(fileBytes)
	lines := strings.Split(fileContent, "\r")
	var pclass int
	var age int
	fmt.Scan(&pclass, &age)
	var names []person
	for _, line := range lines[1:] {
		var bufpass person = split(line)
		if bufpass.Sex == "" || bufpass.Age == -1 || bufpass.Pclass == -1 || bufpass.Name == "" {
			continue
		}
		if bufpass.Sex == "female" && bufpass.Pclass == pclass && bufpass.Age > age {
			names = append(names, bufpass)
		}
	}
	sort.Sort(PassengerS(names))
	for _, name := range names {
		fmt.Println(name.Name)
	}
}

//KST
