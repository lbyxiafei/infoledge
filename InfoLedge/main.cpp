#include <bits/stdc++.h>
#include <QApplication>
#include <QPushButton>

using namespace std;

int main(int argc, char **argv){
    QApplication app(argc, argv);

    QPushButton button;
    button.setText("My text");
    button.setToolTip("A tooltip");

    QFont font("Courier");
    button.setFont(font);

    QIcon icon("../InfoLedge/resources/avatar.jpg");
    button.setIcon(icon);
    //button.setIcon(QIcon::fromTheme("face-smile"));

    button.show();

    return app.exec();
}
