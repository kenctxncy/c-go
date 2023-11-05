package main

import "fmt"

func shift(data []int, steps int) {
	if steps > 0 {
		for i := 0; i < steps; i++ {
			last_elem := data[len(data)-1]
			copy(data[1:], data[:len(data)-1])
			data[0] = last_elem
		}
	} else {
		for i := 0; i > steps; i-- {
			first_elem := data[0]
			copy(data[:len(data)-1], data[1:])
			data[(len(data) - 1)] = first_elem
		}
	}
}

func main() {
	var steps int
	fmt.Scan(&steps)

	var data [10]int
	for index := range data {
		fmt.Scan(&data[index])
	}

	shift(data[:], steps)
	for _, value := range data {
		fmt.Printf("%d ", value)
	}
}
