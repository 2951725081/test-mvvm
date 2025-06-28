#pragma once
#include <vector>
#include <string>
#include <functional>
#include "../model/student.h"

class StudentViewModel {
public:
    using Callback = std::function<void()>;

    void addStudent(const std::string& name, int age);
    const std::vector<Student>& getStudents() const;

    void setOnChangeCallback(Callback cb);

private:
    std::vector<Student> students;
    Callback onChange;
};
