package main

import (
	"fmt"
)

func main() {
	var row, col int
	fmt.Scan(&row, &col)

	fmt.Print("    |")
	for j := 1; j <= col; j++ {
		fmt.Printf("%4d", j)
	}
	fmt.Println()

	fmt.Print("   --")
	for j := 1; j <= col; j++ {
		fmt.Print("----")
	}
	fmt.Println()

	for i := 1; i <= row; i++ {
		fmt.Printf("%4d|", i)
		for j := 1; j <= col; j++ {
			fmt.Printf("%4d", i*j)
		}
		fmt.Println()
	}
}
