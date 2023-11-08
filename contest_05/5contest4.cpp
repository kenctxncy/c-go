#include <iostream>
#include "json.hpp"
using json = nlohmann::json;

#include <cmath>
class Point {
public:
    Point(double x, double y) : x(x), y(y) {}
    double get_x() const {
        return x;
    }
    double get_y() const {
        return y;
    }
    double get_r() const {
        return std::sqrt(pow(x, 2) + pow(y, 2));
    }
    double get_a() const {
        return std::atan2(y, x);
    }

    void set_x(double x) {
        this->x = x;
    }
    void set_y(double y) {
        this->y = y;
    }
    void set_r(double r) {
        double a = get_a();
        x = r * std::cos(a);
        y = r * std::sin(a);
    }
    void set_a(double a) {
        double r = get_r();
        x = r * std::cos(a);
        y = r * std::sin(a);
    }
private:
    double x, y;
};

int main() {
    double x, y;
    std::cin >> x >> y;

    Point p(x, y);
    json moves;
    std::cin >> moves;

    for (auto& move : moves) {
        std::string ort = move["ort"];
        double value = move["value"];
        if (ort == "x") p.set_x(p.get_x() + value);
        else if (ort == "y") p.set_y(p.get_y() + value);
        else if (ort == "r") p.set_r(p.get_r() + value);
        else p.set_a(p.get_a() + value);
        std::cout << round(p.get_x() * (1E+5)) / (1E+5) << ' ' << round(p.get_y() * (1E+5)) / (1E+5) << std::endl;
    }
}