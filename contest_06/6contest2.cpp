#include<iostream>
#include<string>
#include<map>
/// <summary>
/// dlya spravki ya do six por ne ponyal pochemu u menya vivod vo vtorom primere vsegda toi zhe zarplatu chto i po usloviyu
/// </summary>
std::map<std::string, double> bonuses;
//sss
#include <cmath>

class Employee {
public:
    Employee(const std::string& name, const std::string& position, int salary) : name(name), position(position), salary(salary) {}

    virtual int bonus(double percent) {
        return round(salary * percent);
    }

    int total_cash(double bonusPercent) {
        return salary + bonus(bonusPercent);
    }

    friend std::ostream& operator<<(std::ostream& out, Employee& dude) {
        out << dude.name << " (" << dude.position << "): " << dude.total_cash(bonuses[dude.position]);
        return out;
    }

protected:
    std::string name, position;
    int salary;
};

class Manager : public Employee {
public:
    Manager(const std::string& name, int money = 16242)
        :Employee(name, "manager", money) {
    }

    int bonus(double percent) override {
        double actualPercent = (percent < 0.1) ? 0.1 : percent;
        return round(salary * actualPercent);
    }
};

//sss
class Boss : public Employee {
public:
    Boss(std::string name, int money = 16242)
        :Employee(name, "boss", money) {
    }
};

int main() {
    double boss_bonus, manager_bonus;
    std::cin >> boss_bonus >> manager_bonus;
    bonuses["manager"] = manager_bonus;
    bonuses["boss"] = boss_bonus;

    int john_money, bob_money, alice_money;
    std::cin >> john_money >> bob_money >> alice_money;
    Boss john("John", john_money);
    Manager bob("Bob", bob_money);
    Manager alice("Alice", alice_money);

    std::cout << john << '\n' << bob << '\n' << alice << std::endl;
}