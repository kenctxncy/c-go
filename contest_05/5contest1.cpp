#include <iostream>

class Cat {
public:
    bool is_alive() {
        return alive;
    }
private:
    bool alive = rand() % 2;
};

class Box {
public:
    Cat open() {
        return Cat();
    }
};

int main()
{
    Box box;
    Cat cat = box.open();
    if (cat.is_alive()) std::cout << "alive";
    else std::cout << "dead";
}
