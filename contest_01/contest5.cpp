#include <cmath>
#include <iostream>

int main()
{
    double M;
    double H;
    std::cin >> M >> H;
    if (H!=0)
    {
        std::cout << M / pow(H, 2);
    }
}