package main

import (
	"fmt"
)

func graph(n int, dann []int) []float64 {
	glad := make([]float64, n)

	glad[0] = float64(dann[0])
	glad[n-1] = float64(dann[n-1])

	for i := 1; i < n-1; i++ {
		glad[i] = (float64(dann[i-1]) + float64(dann[i]) + float64(dann[i+1])) / 3.0
	}

	return glad
}

func main() {
	var n int
	fmt.Scan(&n)

	dann := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&dann[i])
	}

	itog := graph(n, dann)

	for i := 0; i < n; i++ {
		fmt.Printf("%.10f", itog[i])
		if i < n-1 {
			fmt.Print(" ")
		}
	}
}
