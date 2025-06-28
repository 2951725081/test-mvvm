#include "studentviewmodel.h"

void StudentViewModel::addStudent(const std::string& name, int age) {
    students.push_back({ name, age });
    if (onChange) onChange();
}

const std::vector<Student>& StudentViewModel::getStudents() const {
    return students;
}

void StudentViewModel::setOnChangeCallback(Callback cb) {
    onChange = cb;
}
