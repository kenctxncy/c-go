#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
int main() {
    std::string word;
    std::map<std::string, int> wordCount;
    std::set<std::string> repeatedWords;

    while (true) {
        std::cin >> word;
        if (word == "end") {
            break;
        }

        if (word.length() == 3) {
            bool isValid = true;
            for (char c : word) {
                if (!std::islower(c)) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                wordCount[word]++;
            }
        }
    }

    for (const auto& pair : wordCount) {
        if (pair.second > 1) {
            repeatedWords.insert(pair.first);
        }
    }

    for (const std::string& word : repeatedWords) {
        std::cout << word << " ";
    }
}


