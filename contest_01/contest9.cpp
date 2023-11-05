#include <cmath>
#include <iostream>

int main()
{
	double A;
	double B;
	std::cin >> A;
	std::cin >> B;
	if (A>0 && B>0)
	{
		std::cout << sqrt(pow(A, 2) + pow(B, 2));
	}
	else {
		return 0;
	}
}
