#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Multiline_Output.H>
#include "../viewmodel/studentviewmodel.h"

class StudentView {
public:
    StudentView(StudentViewModel& vm);
    void show();

private:
    void updateView();

    Fl_Window* window;
    Fl_Input* nameInput;
    Fl_Input* ageInput;
    Fl_Button* addButton;
    Fl_Multiline_Output* output;

    StudentViewModel& viewModel;
};
