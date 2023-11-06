package main

import (
	"bufio"
	"fmt"
	"os"
)

func isLucky(x string) bool {
	if int(x[0])+int(x[1])+int(x[2]) == int(x[3])+int(x[4])+int(x[5]) {
		return true
	} else {
		return false
	}
}

func main() {
	number, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isLucky(number[:len(number)-1]) { // Обрезаем \n в конце строки
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
