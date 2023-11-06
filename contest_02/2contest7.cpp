#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

struct Course {
    std::string name;
    int semester;
    bool finished;
};

struct Student {
    std::string name;
    std::string group;
    std::vector<Course> courses;
};

std::string edit(std::string& line) {
    std::string name = line.substr(0, line.find(';'));
    line = line.substr(line.find(';') + 1);
    return name;
}
Student make_student(std::string line) {
    std::string name = edit(line);
    std::string group = edit(line);
    std::vector<Course> courses;
    Student student = Student();
    student.name = name;
    student.group = group;
    while (line.length() != 1) {
        std::string subject = edit(line);
        int semester = std::stoi(edit(line));
        bool finished = std::stoi(edit(line));
        student.courses.push_back(Course{ name = subject, semester = semester, finished = finished });
    }
    return student;
}
bool is_upper(Student stud1, Student stud2) {
    if (stud1.group < stud2.group) {
        return true;
    }
    else if (stud1.group > stud2.group) {
        return false;
    }
    else if (stud1.name < stud2.name) {
        return true;
    }
    else {
        return false;
    }
}

bool is_debtor(Student student, int cur_semester, int max_debt) {
    int debt_count = 0;
    std::vector<Course> all_course = student.courses;
    for (auto& info : all_course) {
        int semester = info.semester;
        bool finished = info.finished;
        if (semester < cur_semester&& finished == false) {
            debt_count++;
        }
    }
    return debt_count > max_debt;
}


void print(std::vector<Student> students) {
    if (students.empty())std::cout << "Empty list!";

    else {
        Student prev = students[0];
        std::cout << prev.group << std::endl;
        int k = 0;
        for (auto& student : students) {

            if (k == 0) {
                k += 1;
                continue;
            }
            std::cout << "- " << prev.name << std::endl;
            if (prev.group != student.group) {
                std::cout << student.group << std::endl;

            }
            if (prev.name == students[students.size() - 2].name && prev.group == students[students.size() - 2].group) {

                std::cout << "- " << students[students.size() - 1].name << std::endl;

            }
            prev = student;
            k += 1;

        }

    }
}

int main() {
    int cur_semester, max_debt, stud_count;
    std::cin >> stud_count >> cur_semester >> max_debt;
    std::cin.ignore(1);
    std::vector<Student> students(stud_count);
    for (auto& student : students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }

    std::vector<Student> expulsion_candidates;
    std::copy_if(students.begin(),
        students.end(),
        std::back_inserter(expulsion_candidates),
        [cur_semester, max_debt](const Student& student) {
            return is_debtor(student, cur_semester, max_debt);
        });

    std::sort(expulsion_candidates.begin(), expulsion_candidates.end(), is_upper);
    print(expulsion_candidates);

    return 0;
}
//I absolutely hate this problem
