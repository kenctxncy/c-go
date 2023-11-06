#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


std::map<int, std::string> parseLine(std::string s) {
    int j = 0;
    bool quotes = true;
    bool nquotes = false;
    std::string buffer = "";
    std::map<int, std::string> b1;
    for (const auto& i : s) {
        if (i == ',') {
            if (quotes or nquotes) {
                b1[j] = buffer;
                buffer = "";
                j += 1;
            }
            else {
                buffer += i;
            }
        }
        else if (i == '\"' and quotes) {
            quotes = false;
        }
        else if (i == '\"' and nquotes) {
            buffer += "\"";
            nquotes = false;
        }
        else if (i == '\"') {
            nquotes = true;
        }
        else {
            buffer += i;
        }
    }
    return b1;
}

int main() {

    std::ifstream file("train.csv");
    std::string line;
    std::vector<std::map<int, std::string>> passengers;
    int age, pclass;
    std::cin >> pclass >> age;
    getline(file, line, '\r');
    while (not file.eof()) {
        getline(file, line, '\r');
        std::map<int, std::string> bufm = parseLine(line);
        if (bufm[4] == "" or bufm[2] == "" or bufm[5] == "") {
            continue;
        }
        if (bufm[4] == "female" and pclass == std::stoi(bufm[2]) and std::stoi(bufm[5]) > age) {
            passengers.emplace_back(bufm);
        }
    }
    file.close();
    std::sort(passengers.begin(), passengers.end(), [](std::map<int, std::string> p1, std::map<int, std::string> p2) {if (std::stoi(p1[5]) == std::stoi(p2[5])) {
        return p1[3] < p2[3];
    }
    return std::stoi(p1[5]) < std::stoi(p2[5]); });
    for (auto passenger : passengers) {
        std::cout << passenger[3] << std::endl;
    }
    return 0;
}
/* RIP Yepishenko Yaroslav's hopes and dreams and motivation and LIFE.........
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct Passenger {
    std::string name, sex;
    int pclass, age;
};

bool comp(const Passenger& a, const Passenger& b) {
    if (a.age == b.age) {
        return a.name < b.name;
    }
    return a.age < b.age;
}

Passenger parseLine(const std::string& line) {
    Passenger p;
    std::string field;
    int column = 0;
    bool in_quotes = false;
    for (char c : line) {
        if (c == '\"') {
            in_quotes = !in_quotes;
        }
        else if (c == ',' && !in_quotes) {
            switch (column) {
            case 2: p.pclass = std::stoi(field); break;
            case 3: p.name = field; break;
            case 4: p.sex = field; break;
            case 5: p.age = std::stoi(field); break;
            }
            field.clear();
            ++column;
        }
        else {
            field += c;
        }
    }
    return p;
}

int main() {
    std::ifstream file("train.csv");
    std::string line;
    std::vector<Passenger> passengers;
    int target_age;
    int target_pclass;
    std::cin >> target_pclass;
    std::cin >> target_age;
    std::getline(file, line, '\r');
    while (std::getline(file, line, '\r')) {
        try {
            Passenger p = parseLine(line);
            if (p.sex == "female" && target_pclass == p.pclass && p.age > target_age) {
                passengers.emplace_back(p);
            }
        }
        catch (const std::invalid_argument& e) {
        }
        catch (const std::out_of_range& e) {
        }
    }
    std::sort(passengers.begin(), passengers.end(), comp);
    for (const auto& p : passengers) {
        std::cout << p.name << std::endl;
    }
    return 0;
}
*/