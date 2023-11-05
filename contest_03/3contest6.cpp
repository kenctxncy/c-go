#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main()
{
    long long int n, m;
    std::string log_inp, l, b;
    std::unordered_map<std::string, std::string> login_data;

    std::cin >> n;

    for (long long int i = 0; i < n; i++)
    {
        std::cin >> log_inp;
        std::size_t position = log_inp.find(';');
        l = log_inp.substr(0, position);
        b = log_inp.substr(position + 1);
        login_data[l] = b;
    }

    std::cin >> m;

    std::vector<std::string> query(m);

    for (long long int i = 0; i < m; ++i)
    {
        std::cin >> query[i];
    }

    for ( const auto &elem : query)
    {
        std::cout << login_data[elem] << " ";
    }
    return 0;
}