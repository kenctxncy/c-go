#include <iostream>
#include <string>

#include <algorithm>
#include <vector>
typedef long long int tiny;
class Bigint {
    inline int abs(int x) { return x < 0 ? -x : x; }
    inline int mod(int x, int y) { return (x % y + y) % y; }
    inline int div(int x, int y) { return x / y - (x % y != 0 && x < 0); }
public:
    std::vector<int> nums{ 0 };
    int sign = 1;
    Bigint() {}
    Bigint(int in) {
        if (in == 0) return;
        nums.pop_back();
        sign = in < 0 ? -1 : 1;
        in = in < 0 ? -in : in;
        while (in > 0) {
            nums.push_back(in % 10);
            in /= 10;
        }
    }
    Bigint(std::string in) {
        nums.pop_back();
        bool minus = in.at(0) == '-';
        if (minus) sign = -1;
        for (tiny i = minus; i < in.size(); i++)
            nums.push_back(in.at(i) - '0');
        std::reverse(nums.begin(), nums.end());
    }
    Bigint operator+(const Bigint& y) {
        char signX = sign; char signY = y.sign; Bigint xval = *this; Bigint yval = y; xval.sign = yval.sign = 1; Bigint gtr; Bigint lss; char switcher = 1;
        if (xval < yval) {
            lss = xval; gtr = yval;
            if (signX == 1) switcher = signY;
        }
        else {
            gtr = xval; lss = yval;
            if (signY == 1) switcher = signX;
        }
        tiny ind = 0; char cntnmnt = 0; Bigint res; res.nums.pop_back();
        while (ind < gtr.nums.size() || ind < lss.nums.size() || cntnmnt != 0) {
            char sum = cntnmnt;
            if (ind < gtr.nums.size()) sum += gtr.nums[ind];
            if (ind < lss.nums.size()) sum += lss.nums[ind] * signX * signY;
            res.nums.push_back(mod(sum, 10));
            cntnmnt = div(sum, 10);
            ind++;
        }
        res.sign = signX == signY ? signX : switcher;
        while (res.nums[res.nums.size() - 1] == 0 && res.nums.size() > 1)
            res.nums.pop_back();
        return res;
    }
    Bigint operator-(const Bigint& y) {
        Bigint temp = y; temp.sign *= -1;
        return (*this) + temp;
    }
    Bigint operator*(const Bigint& y) {
        Bigint ans; Bigint xval = *this; Bigint yval = y;
        xval.sign = yval.sign = 1;
        for (tiny i = 0; i < xval.nums.size(); i++) {
            tiny j = 0; long int cntnmnt = 0; Bigint temp; temp.nums.pop_back();
            while (j < yval.nums.size() || cntnmnt != 0) {
                long int semi = cntnmnt;
                if (j < yval.nums.size()) semi += yval.nums[j] * xval.nums[i];
                temp.nums.push_back(mod(semi, 10));
                cntnmnt = div(semi, 10);
                j++;
            }
            for (tiny j = 0; j < i; j++) temp.nums.insert(temp.nums.begin(), 0);
            ans = ans + temp;
        }
        ans.sign = sign * y.sign;
        return ans;
    }
    Bigint operator/(const Bigint& y) {
        Bigint ans; Bigint xval = *this; Bigint yval = y;
        xval.sign = yval.sign = 1;
        while (xval.sign == 1) {
            xval = xval - yval;
            ans = ans + Bigint(1);
        }
        ans = ans - Bigint(1);
        ans.sign = sign * y.sign;
        return ans;
    }
    bool operator==(const Bigint& y) {
        if (nums.size() != y.nums.size()) return false;
        for (tiny i = 0; i < nums.size(); i++)
            if (nums[i] != y.nums[i]) return false;
        return sign == y.sign;
    }
    bool operator<(const Bigint& y) {
        if (*this == y) return false;
        if (sign < y.sign) return true;
        if (sign > y.sign) return false;
        if (nums.size() < y.nums.size()) return true;
        if (nums.size() > y.nums.size()) return false;
        tiny i = nums.size() - 1;
        while (nums[i] == y.nums[i]) i--;
        return nums[i] < y.nums[i];
    }
    bool operator>(const Bigint& y) {
        return !(*this < y || *this == y);
    }
    friend std::ostream& operator<<(std::ostream& out, const Bigint& a) {
        out << (a.sign == -1 && !(Bigint(0) == a) ? "-" : "");
        for (tiny i = a.nums.size() - 1; i > 0; i--)
            out << (char)(a.nums[i] + '0');
        out << (char)(a.nums[0] + '0');
        return out;
    }
};
int main() {
    std::string a, b;
    std::cin >> a >> b;

    Bigint first(a);
    Bigint second(b);

    std::cout << "a + b = " << (first + second) << std::endl;
    std::cout << "a - b = " << (first - second) << std::endl;
    std::cout << "a * b = " << (first * second) << std::endl;
    std::cout << "a / b = " << (first / second) << std::endl;

    int c;
    std::cin >> c;
    Bigint third(c);
    Bigint zero;

    std::cout << "с > 0 = " << (third > zero) << std::endl;
    std::cout << "с < 0 = " << (third < zero) << std::endl;
    std::cout << "с == 0 = " << (third == zero) << std::endl;
}
//yanexochudelatdeleniyeknuta
//sponsoredbytheshadowgovernment