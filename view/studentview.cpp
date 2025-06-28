#include "studentview.h"
#include <sstream>
#include <cstdlib>

StudentView::StudentView(StudentViewModel& vm) : viewModel(vm) {
    window = new Fl_Window(400, 300, "FLTK MVVM Example");

    nameInput = new Fl_Input(80, 20, 200, 25, "Name:");
    ageInput = new Fl_Input(80, 60, 200, 25, "Age:");
    addButton = new Fl_Button(300, 60, 80, 25, "Add");
    output = new Fl_Multiline_Output(20, 100, 360, 160);

    addButton->callback([](Fl_Widget*, void* data) {
        auto* self = static_cast<StudentView*>(data);
        std::string name = self->nameInput->value();
        int age = std::atoi(self->ageInput->value());
        self->viewModel.addStudent(name, age);
        self->nameInput->value("");
        self->ageInput->value("");
    }, this);

    viewModel.setOnChangeCallback([this]() { updateView(); });
}

void StudentView::show() {
    window->end();
    window->show();
}

void StudentView::updateView() {
    std::ostringstream oss;
    for (const auto& s : viewModel.getStudents()) {
        oss << s.name << " (" << s.age << ")\n";
    }
    output->value(oss.str().c_str());
}
