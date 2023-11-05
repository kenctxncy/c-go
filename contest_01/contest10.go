package main

import "fmt"

func main() {
	var a, b, c string
	fmt.Scanf("%s %s %s", &a, &b, &c)
	ans := a + b + c
	switch ans {
	case "НетНетНет":
		fmt.Println("Кот")
	case "НетНетДа":
		fmt.Println("Жираф")
	case "НетДаНет":
		fmt.Println("Курица")
	case "НетДаДа":
		fmt.Println("Страус")
	case "ДаНетНет":
		fmt.Println("Дельфин")
	case "ДаНетДа":
		fmt.Println("Плезиозавры")
	case "ДаДаНет":
		fmt.Println("Пингвин")
	case "ДаДаДа":
		fmt.Println("Утка")
	}
}
