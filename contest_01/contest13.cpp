#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int c_l = 0, s_l = 1, m_l = 2, uod = 1;
	for (int i = 1; i <= n; i++)
	{
		std::cout << i << " ";
		c_l++;
		if (c_l==s_l)
		{
			std::cout << "\n";
			s_l += uod;
			c_l = 0;
		}
		if (s_l==m_l||s_l==1)
		{
			uod *= -1;
		}
		if (s_l == m_l)
		{
			m_l++;
		}
	}
	return 0;
}