package main

import (
	"fmt"
	"math/rand"
)

type Cat struct {
	alive bool
}

type Box struct{}

func (c *Cat) is_alive() bool {
	return c.alive
}

func (b Box) open() Cat {
	return Cat{rand.Intn(2) == 0}
}

func main() {
	var box Box
	cat := box.open()
	if cat.is_alive() {
		fmt.Print("alive")
	} else {
		fmt.Print("dead")
	}
}
