#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool compare(std::string x, std::string y){
    if (count(x.begin(), x.end(), '1') != count(y.begin(), y.end(), '1')) {
        return count(x.begin(), x.end(), '1') > count(y.begin(), y.end(), '1');
    }
    else {
        return std::stoi(x,nullptr,2) < std::stoi(y,nullptr,2);
    }
}

int main() {
    int count;
    std::cin >> count;

    std::vector<std::string> nums(count);
    for (auto& line : nums) std::cin >> line;

    std::sort(nums.begin(), nums.end(), compare);

    for (auto& line : nums) std::cout << line << ' ';
}
