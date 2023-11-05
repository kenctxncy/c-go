package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isPalindrome(line string) bool {
	filtered := ""
	for _, elem := range line {
		if (elem >= 'a' && elem <= 'z') || (elem >= 'A' && elem <= 'Z') || (elem >= '0' && elem <= '9') {
			filtered += string(elem)
		}
	}
	filtered = strings.ToLower(filtered)
	for i := 0; i < len(filtered)/2; i++ {
		if filtered[i] != filtered[len(filtered)-1-i] {
			return false
		}
	}
	return true
}

func main() {
	line, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isPalindrome(line[:len(line)-1]) { // Обрезаем \n в конце строки
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
