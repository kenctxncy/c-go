#include <iostream>

#include <cmath>
bool is_prime(long long int number){
    for (int i = 2; i < sqrt(abs(number)); i++)
    {
        if (number%i==0)
        {
            return false;
            break;
        }
    }
    return true;
}

int main() {
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}