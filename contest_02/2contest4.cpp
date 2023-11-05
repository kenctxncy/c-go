#include <iostream>
#include <tuple>

#include <numeric>
std::tuple<long long int, long long int, long long int> find_lcm(long long int a, long long int b) {
    long long int c = std::lcm(a, b);
}
std::tuple<long long int, long long int> reduce(long long int a, long long b) {
    long long int c = std::gcd(a, b);
    return std::make_tuple(a / c, b / c);
}

int main() {
    int m1, n1, m2, n2;
    char _;

    std::cin >> m1 >> _ >> n1
        >> m2 >> _ >> n2;
    std::tie(m1, n1) = reduce(m1, n1);
    std::tie(m2, n2) = reduce(m2, n2);

    auto [lcm, c1, c2] = find_lcm(n1, n2);
    auto [m, n] = reduce(m1 * c1 + m2 * c2, lcm);

    std::cout << m << '/' << n << std::endl;
}