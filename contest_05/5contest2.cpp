#include <iostream>
#include <deque>

class Water {
public:
    Water(int tCelsius) : temperature(tCelsius){}
    void heat(int tCelsius) { temperature += tCelsius; }
    bool is_boiling() { return temperature >= 100; }
private:
    int temperature;
};

class Teapot {
public:
    Teapot(Water& amount) : water(amount) {}
    void heat_up(int tCelsius) { water.heat(tCelsius); }
    bool is_boiling() { return water.is_boiling(); }
private:
    Water& water;
};

int main()
{
    int temperature, count;
    std::cin >> temperature >> count;
    std::deque<int> heat(count);
    for (auto& t : heat) std::cin >> t;

    Water water(temperature);
    Teapot teapot(water);

    while (not teapot.is_boiling()) {
        teapot.heat_up(heat.front());
        heat.pop_front();
    }

    for (auto t : heat) std::cout << t << ' ';
}