#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
	std::map<std::string, int> words_sort;
	std::string word;
	long long int n;
	int max_w = 0;
	std::vector<std::string> frequent;

	std::cin >> n;

	for (long long int i = 0; i < n; i++)
	{
		std::cin >> word;
		++words_sort[word];
	}

	for (const auto &pair : words_sort)
	{
		max_w = std::max(max_w, pair.second);
	}

	for (const auto &pair : words_sort)
	{
		if (pair.second==max_w)
		{
			frequent.push_back(pair.first);
		}
	}

	std::sort(frequent.begin(), frequent.end());

	for (const auto &word : frequent)
	{
		std::cout << word << " ";
	}
	return 0;
}
