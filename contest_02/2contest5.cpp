//Complex make_complex(const std::string& num) {
//    std::stringstream ss(num);
//    Complex c;
//    ss >> c.re >> c.im;
//    return c;
//}


#include <iostream>

struct Complex {
    double re;  // Действительная часть
    double im;  // Мнимая часть
};



#include <cmath>
#include <sstream>
#include <string>

Complex make_complex(std::string num) {
    bool is_minus = false;
    bool is_plus = false;
    std::string first;
    std::string second;
    for (char c : num) {
        if (c == '-') {
            is_minus = true;
            continue;

        }
        else if (c == '+') {
            is_plus = true;
            continue;
        }
        if (!(is_plus || is_minus) && c != ' ') {
            first += c;
        }
        else if ((is_plus || is_minus) && c != ' ') {
            if (first.length() == 0) {
                first += '-';
                first += c;
                is_minus = false;
                continue;
            }
            second += c;
        }
    }
    double re = std::stod(first);
    double im = std::stod(second);
    if (is_minus) {
        im *= -1;
    }
    Complex complex;
    complex.re = re;
    complex.im = im;
    return complex;

}


Complex sum(Complex c1, Complex c2) {
    Complex result;
    result.re = c1.re + c2.re;
    result.im = c1.im + c2.im;
    if (c1.im + c2.im == 0) {
        result.im = 0.;
    }
    return Complex{ result.re,result.im };
}
Complex sub(Complex c1, Complex c2) {
    return Complex{ c1.re - c2.re, c1.im - c2.im };
}
Complex mul(Complex c1, Complex c2) {
    Complex result;
    result.re = c1.re * c2.re - c1.im * c2.im;
    result.im = c1.re * c2.im + c1.im * c2.re;
    return Complex{ result.re,result.im };
}
Complex div(Complex c1, Complex c2) {
    Complex result;
    long double den = (c2.re * c2.re) + (c2.im * c2.im);
    result.re = ((c1.re * c2.re) + (c1.im * c2.im)) / den;
    result.im = ((c1.im * c2.re) - (c1.re * c2.im)) / den;
    return result;
}
void print(Complex c) {
    std::cout << c.re;
    if (c.im >= 0) {
        std::cout << "+";
    }
    std::cout << c.im << "j" << std::endl;

}

//void print(const Complex& c) {
//    if (c.re != 0 && c.im != 0) {
//        std::cout << c.re;
//        if (c.im > 0) {
//            std::cout << "+";
//        }
//        std::cout << c.im << "j" << std::endl;
//    } else if (c.re == 0 && c.im != 0) {
//        std::cout << c.im << "j" << std::endl;
//    } else if (c.re != 0 && c.im == 0) {
//        std::cout << c.re << std::endl;
//    } else {
//        std::cout << "0" << std::endl;
//    }
//}