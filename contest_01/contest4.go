package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b float64
	fmt.Scanf("%f %f", &a, &b)
	if math.Abs(a) <= 10000 && math.Abs(b) <= 10000 {
		multi := a * b
		fmt.Printf("%f", multi)
	}
}
