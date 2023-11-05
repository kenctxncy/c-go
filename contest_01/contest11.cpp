#include <iostream>
#include <cstdlib>
#include<algorithm>

int main()
{
    int A, B, C, rd_b, rd_c;
    std::cin >> A >> B >> C;
	if (abs(B)!=abs(C))
	{
		rd_c = abs(A - C);
		rd_b = abs(A - B);

		if (rd_b<rd_c)
		{
			std::cout << "B " << rd_b;
		}
		else {
			std::cout << "C " << rd_c;
		}
	}
	else
	{
		return 0;
	}
}
