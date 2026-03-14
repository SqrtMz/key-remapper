#include "windows/home.hpp"
#include <QApplication>
#include <fcntl.h>
#include <libevdev/libevdev.h>
#include <string>

int main(int argc, char* argv[]) {

    std::cout << getuid() << std::endl;
    
    QApplication app(argc, argv);
    Home *w = new Home();
    w->show();
    return app.exec();

}