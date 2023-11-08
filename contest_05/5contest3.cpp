#include <iostream>
#include <string>

#include <sstream>
#include <cmath>
class Complex {
public:
    double re, im;

    Complex(const std::string& str) {
        std::stringstream iss(str);
        char op = '+';
        iss >> re;
        iss >> std::ws;
        if (iss.peek() == '+' || iss.peek() == '-') {
            iss >> op;
        }
        iss >> std::ws;
        iss >> im;
        if (op == '-') {
            im = -im;
        }
    }

    Complex operator+(const Complex& num2) const {
        return Complex(re + num2.re, im + num2.im);
    }

    Complex operator-(const Complex& num2) const {
        return Complex(re - num2.re, im - num2.im);
    }

    Complex operator*(const Complex& num2) const {
        return Complex(re * num2.re - im * num2.im, re * num2.im + im * num2.re);
    }

    Complex operator/(const Complex& num2) const {
        double del = pow(num2.re, 2) + pow(num2.im, 2);
        double real = (re * num2.re + im * num2.im) / del;
        double imag = (im * num2.re - re * num2.im) / del;
        return Complex(real,imag);
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& num) {
        out << (num.re == 0.0 ? 0.0 : num.re)
            << (num.im < 0 ? "" : "+") << (num.im == 0.0 ? 0.0 : num.im) << 'j';
        return out;
    }

private:
    Complex(double re, double im) : re(re), im(im) {}
};

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1(num);

    std::getline(std::cin, num, 'j');
    Complex c2(num);

    std::cout << c1 + c2 << '\n' << c1 - c2 << '\n'
        << c1 * c2 << '\n' << c1 / c2 << std::endl;
}