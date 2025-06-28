#include "viewmodel/studentviewmodel.h"
#include "view/studentview.h"
#include <FL/Fl.H>

int main(int argc, char** argv) {
    StudentViewModel vm;
    StudentView view(vm);
    view.show();
    return Fl::run();
}
