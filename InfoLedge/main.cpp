#include <QApplication>

#include "menuwindow.h"

using namespace std;

int main(int argc, char **argv){
    QApplication app(argc, argv);

    MenuWindow window;
    window.show();

    return app.exec();
}
