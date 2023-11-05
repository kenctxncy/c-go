#include <iostream>
#include <string>

std::string excel(int n) {
    std::string res = "";

    while (n > 0) {
        int ost = (n - 1) % 26;
        char col = 'A' + ost;

        res = col + res;

        n = (n - 1) / 26;
    }

    return res;
}

int main() {
    int n;
    std::cin >> n;

    std::string colN = excel(n);

    std::cout << colN << std::endl;
}