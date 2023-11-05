package main

import "fmt"

func collatz_conjecture(x float64) int {
	steps := 0
	for x > 1 {
		if int(x)%2 == 0 {
			x /= 2
			steps++
		} else {
			x = x*3 + 1
			steps++
		}
	}
	return steps
}

func main() {
	var x float64
	fmt.Scanf("%f", &x)
	fmt.Printf("%d", collatz_conjecture(x))
}
