#include <iostream>
#include <algorithm>
int main()
{
	std::string num_in, num_out;
	std::cin >> num_in >> num_out;
	std::sort(num_in.begin(), num_in.end());
	std::sort(num_out.begin(), num_out.end());
	std::cout << (num_in == num_out ? "YES" : "NO");
	return 0;
}