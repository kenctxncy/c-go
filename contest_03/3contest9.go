package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, goal int

	fmt.Scan(&n, &goal)

	numStr := make([]int, n)

	for i := range numStr {
		fmt.Scan(&numStr[i])
	}

	numMap := make(map[int]bool)

	for _, number := range numStr {
		if numMap[goal-number] {
			output := []int{goal - number, number}
			sort.Ints(output)
			fmt.Printf("%v %v", output[0], output[1])
			return
		}
		numMap[number] = true
	}
	fmt.Println(0, 0)
}
