#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isoperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

bool LowPriority(char operand1, char operand2) {
	if ((operand1 == '+' || operand1 == '-') && (operand2 == '+' || operand2 == '-'))
	{
		return true;
	}
	if ((operand1 == '*' || operand1 == '/' || operand1 == '%') && (operand2 == '*' || operand2 == '/' || operand2 == '%' || operand2 == '+' || operand2 == '-'))
	{
		return true;
	}
	if ((operand1 == '^') && (operand2 == '+' || operand2 == '-' || operand2 == '*' || operand2 == '/' || operand2 == '%'))
	{
		return true;
	}
	return false;
}

std::string convertation(std::string input) {
	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
	std::stack<char> op_stack;
	std::string output;
	output.reserve(input.size() * 2);
	for (int i = 0; i < input.size(); ++i)
	{
		char c = input[i];
		if (isdigit(c))
		{
			while (i < input.size() && isdigit(input[i]))
			{
				output.push_back(input[i]);
				++i;
			}
			output.push_back(' ');
			--i;
		}
		else if (isoperator(c))
		{
			while (!op_stack.empty() && isoperator(op_stack.top()) && LowPriority(op_stack.top(), c))
			{
				output.push_back(op_stack.top());
				output.push_back(' ');
				op_stack.pop();
			}
			op_stack.push(c);
		}
		else if (c == '(')
		{
			op_stack.push(c);
		}
		else if (c == ')')
		{
			while (!op_stack.empty() && op_stack.top() != '(')
			{
				output.push_back(op_stack.top());
				output.push_back(' ');
				op_stack.pop();
			}
			op_stack.pop();
		}
	}
	while (!op_stack.empty())
	{
		output.push_back(op_stack.top());
		output.push_back(' ');
		op_stack.pop();
	}
	return output;
}

int main()
{
	std::string inp;
	std::getline(std::cin, inp);
	std::string outp_rpn = convertation(inp);
	std::cout << outp_rpn << std::endl;
	return 0;
}
//felt devastating.
