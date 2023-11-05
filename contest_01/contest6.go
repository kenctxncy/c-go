package main

import "fmt"

func n_5000(x int) int {
	return x / 5000

}

func n_1000(x int) int {
	return x % 5000 / 1000

}

func n_500(x int) int {
	return x % 5000 % 1000 / 500

}

func n_200(x int) int {
	return x % 5000 % 1000 % 500 / 200

}

func n_100(x int) int {
	return x % 5000 % 1000 % 500 % 200 / 100

}

func main() {
	var cash int
	fmt.Scanf("%d", &cash)
	if cash%100 == 0 {
		fmt.Printf("%d %d %d %d %d", n_5000(cash), n_1000(cash), n_500(cash), n_200(cash), n_100(cash))
	}
}
