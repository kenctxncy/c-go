package main

import (
	"fmt"
	"math"
)

const (
	Oxygen_h   = 0.5
	Oxygen_o_y = 20
	Oxygen_t_y = 32
)

func main() {
	var hum_res = 365 * Oxygen_h
	var top_res = hum_res / Oxygen_t_y
	var oak_res = hum_res / Oxygen_o_y
	fmt.Println(hum_res, math.Ceil(top_res), math.Ceil(oak_res))
}
