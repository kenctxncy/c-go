#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string group;
};


Student make_student(const std::string& line)
{
    Student student;
    std::size_t position = line.find(';');
    student.name = line.substr(0,position);
    student.group = line.substr(position + 1);
    return student;
}
bool is_upper(const Student& student1, const Student& student2)
{
    if (student1.group < student2.group)
    {
        return true;
    }
    else if (student1.group == student2.group) 
    {
        return student1.name < student2.name;
    }
    else
    {
        return false;
    }
}
void print(std::vector<Student>& students)
{
    if(students.empty())
    {
        std::cout << "Empty list!" << std::endl;
        return;
    }
    std::string curr_grp = students[0].group;
    std::cout << curr_grp << std::endl;
    for(const auto& student : students)
    {
        if(student.group != curr_grp)
        {
            curr_grp = student.group;
            std::cout << curr_grp << std::endl;
        }
        std::cout << "- " << student.name << std::endl;
    }
}


int main()
{
    int count;
    std::cin >> count;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline

    std::vector<Student> students(count);
    for (auto& student : students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }

    std::sort(students.begin(), students.end(), is_upper);

    print(students);
}
