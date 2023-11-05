package main

import "fmt"

func main() {
	var numbersC int
	numbers := map[int64]bool{}

	fmt.Scan(&numbersC)

	for i := 0; i < numbersC; i++ {
		var n int64
		fmt.Scan(&n)

		if _, found := numbers[n]; found {
			delete(numbers, n)
		} else {
			numbers[n] = true //PE without this
		}
	}
	for word, _ := range numbers {
		fmt.Println(word)
	}
}
