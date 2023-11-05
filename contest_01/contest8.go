package main

import "fmt"

func mx(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func main() {
	var a, b, c, temp int
	fmt.Scanf("%d %d %d", &a, &b, &c)
	temp = mx(a, b)
	if mx(a, b) > c {
		fmt.Printf("%d", temp)
	} else {
		fmt.Printf("%d", c)
	}
}
