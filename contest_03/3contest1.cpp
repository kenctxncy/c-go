#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long int n, m;
    std::cin >> n;
    std::vector<long long int > numbers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }
    std::cin >> m;
    numbers.resize(n + m);
    for (int i = n; i < n + m; i++) std::cin >> numbers[i];
    std::sort(numbers.begin(), numbers.end());
    for (int i = 0; i < n + m; i++) std::cout << numbers[i] << " ";
    return 0;
}