#include <iostream>
#include <stack>
#include <string>
bool check(std::string txt) {
	std::stack<char> stack;
	for (char c : txt)
	{
		switch (c)
		{
		case '(':
			stack.push(')');
			break;
		case '[':
			stack.push(']');
			break;
		case '{':
			stack.push('}');
			break;
		case ')':
		case ']':
		case '}':
			if (stack.empty()) {
				return false;
			}
		default:
			break;
		}
		switch (c)
		{
		case ')':
		case ']':
		case '}':
			if (c == stack.top()) {
				stack.pop();
			}
			else {
				return false;
			}
		default:
			break;
		}
	}
	return stack.empty();
}
int main()
{
	std::string input_s;
	std::getline(std::cin, input_s, '!');
	std::cout << (check(input_s) ? "YES" : "NO") << std::endl;
	return 0;
}
