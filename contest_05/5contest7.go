package main

import "fmt"

type Water struct {
	temperature int
}

type Teapot struct {
	water *Water
}

func NewWater(temperature int) *Water {
	return &Water{temperature}
}

func NewTeapot(water *Water) *Teapot {
	return &Teapot{water}
}

func (water *Water) heat_up(temperature int) {
	water.temperature += temperature
}

func (water *Water) is_boiling() bool {
	return water.temperature >= 100
}

func (tpot *Teapot) heat_up(temperature int) {
	tpot.water.heat_up(temperature)
}

func (tpot *Teapot) is_boiling() bool {
	return tpot.water.is_boiling()
}

func main() {
	var temperature, count int
	fmt.Scan(&temperature, &count)

	heat := NewQueue()
	for i := 0; i < count; i++ {
		var t int
		fmt.Scan(&t)
		heat.Push(t)
	}

	water := NewWater(temperature)
	teapot := NewTeapot(water)

	for !teapot.is_boiling() {
		teapot.heat_up(heat.Pop())
	}

	for !heat.IsEmpty() {
		fmt.Print(heat.Pop(), " ")
	}
}
