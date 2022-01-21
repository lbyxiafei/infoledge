#include <QApplication>

#include "mainwindow.h"
#include "menuwindow.h"

using namespace std;

int main(int argc, char **argv){
    QApplication app(argc, argv);

//    MainWindow main_window;
//    main_window.show();

    MenuWindow menu_window;
    menu_window.show();

    return app.exec();
}
