#include <iostream>
#include <fstream>
#include <map>
#include <vector> 
#include <algorithm>


int main()
{
    std::ifstream file("data.txt");
    std::string word;
    std::string target;
    std::map<std::string, long long int> wordmp;
    std::vector<std::string> sorted;

    std::cin >> target;

    std::string previous;
    while (word!="stopword")
    {
        file >> word;
        if (previous==target)
        {
            wordmp[word]++;
        }
        previous = word;
    }

    for (const auto &elem : wordmp)
    {
        sorted.push_back(elem.first);
    }

    if (sorted.empty()) {
        std::cout << "-" << std::endl;
    }
    else {
        std::sort(sorted.begin(), sorted.end(), [&wordmp](const std::string& a, const std::string& b) {
            return (wordmp[a] > wordmp[b]) || (wordmp[a] == wordmp[b] && a < b); //zamena dop funkcii .second > .second || (.second == .second && .first < .first)
            });
        for (long long int i = 0; i < std::min(static_cast<int>(sorted.size()),3); i++)
        {
            std::cout << sorted[i] << " ";
        }
    }
}
