package main

import "fmt"

const rows int = 9
const cols int = 9

func isValidSudoku(sudoku [9][9]int) bool {
	track := make([]int, 10)
	for r := 0; r < 9; r++ {
		for c := 0; c < 9; c++ {
			track[sudoku[r][c]]++
			if track[sudoku[r][c]] > 1 {
				return false
			}
		}
		track = make([]int, 10)
	}
	for c := 0; c < 9; c++ {
		for r := 0; r < 9; r++ {
			track[sudoku[r][c]]++
			if track[sudoku[r][c]] > 1 {
				return false
			}
		}
		track = make([]int, 10)
	}
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			for r := i * 3; r < 3*(i+1); r++ {
				for c := j * 3; c < 3*(j+1); c++ {
					track[sudoku[r][c]]++
					if track[sudoku[r][c]] > 1 {
						return false
					}
				}
			}
			track = make([]int, 10)
		}
	}
	return true
}

func main() {
	var bord [rows][cols]int

	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			fmt.Scanf("%c", &bord[row][col]) // Считываем один символ
			bord[row][col] -= '0'            // Чтобы из ASCII кода символа получить цифру
		}
		fmt.Scanf("\n")
	}

	if isValidSudoku(bord) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
