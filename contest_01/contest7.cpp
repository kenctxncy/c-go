#include <iostream>

int main()
{
    int A;
    int B;
    std::cin >> A >> B;
    if (A>B)
    {
        std::cout << A;
    }
    else if (B>A)
    {
        std::cout << B;
    }
    else
    {
        std::cout << A;
    }
}
