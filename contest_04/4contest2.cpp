#include <iostream>
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

int main()
{
	long long int completed_t = 0;
	json data;
	long long int user_id;
	std::cin >> user_id;

	std::ifstream file("data.json");
	if (!file.is_open())
	{
		std::cerr << "file error" << std::endl;
		return 1;
	}

	file >> data;

	for (const auto& project : data)
	{
		for (const auto& task : project["tasks"])
		{
			if ((task["user_id"]==user_id)&&(task["completed"]==true))
			{
				completed_t++;
			}
		}
	}

	std::cout << completed_t << std::endl;
	
	return 0;
}