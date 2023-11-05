#include <iostream>
#include <set>
#include <algorithm>
#include <sstream>

int main()
{
	long long int n, m;
	std::string txt1, txt2, tmp_w;
	std::set<std::string> base1, base2, result;

	std::cin >> n;
	std::cin.ignore();
	std::getline(std::cin, txt1);
	std::cin >> m;
	std::cin.ignore();
	std::getline(std::cin, txt2);

	std::istringstream iss1(txt1), iss2(txt2);
	while (iss1 >> tmp_w)
	{
		base1.insert(tmp_w);
	}
	while (iss2 >> tmp_w)
	{
		base2.insert(tmp_w);
	}
	std::set_intersection(base1.begin(), base1.end(), base2.begin(), base2.end(), std::inserter(result, result.begin()));

	if (result.empty()) {
		std::cout << "-1" << std::endl;
	}
	else
	{
		for (const std::string& out : result)
		{
			std::cout << out << " ";
		}
	}
	return 0;
}
