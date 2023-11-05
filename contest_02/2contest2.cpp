#include <iostream>
#include <vector>
#include <string>

bool is_can_exit_from_maze(std::vector<std::string> maze, int row, int col) {
    if (maze[row][col] == 'E') {
        return true;
    }
    if (maze[row][col] == '#') {
        return false;
    }
    maze[row][col] = '#';
    return is_can_exit_from_maze(maze, row - 1, col) ||
           is_can_exit_from_maze(maze, row + 1, col) ||
           is_can_exit_from_maze(maze, row, col - 1) ||
           is_can_exit_from_maze(maze, row, col + 1);
}

int main() {
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1); // Игнорируем перевод строки, застрявший в потоке ввода

    std::vector<std::string> maze(rows);
    for (auto& line : maze) std::getline(std::cin, line);


    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}



























//#include <iostream>
//#include <stack>
//
//int main() {
//	std::string data = "";
//	std::getline(std::cin, data, '!');
//
//	std::stack<char> stack;
//	for (char i : data) {
//		if (i == '(' || i == '[' || i == '{') {
//			stack.push(i);
//		}
//		if (i == ')' || i == ']' || i == '}') {
//			if (stack.empty()) {
//				std::cout « "NO" « "\n";
//				return 0;
//			}
//			char temp = stack.top();
//			if (!((temp == '(' && i == ')') || (temp == '[' && i == ']') || (temp == '{' && i == '}'))) {
//				std::cout « "NO" « "\n";
//				return 0;
//			}
//			stack.pop();
//		}
//	}
//	std::cout « "YES" « "\n";
//	return 0;
//}
