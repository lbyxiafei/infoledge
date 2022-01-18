#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv){
    QApplication app(argc, argv);


    QPushButton button;
    button.setText("My text");
    button.setToolTip("A tooltip");


    QFont font("Courier");
    button.setFont(font);

    QIcon icon("C:\\Users\\binyanli\\Repos\\infoledge\\InfoLedge\\resources\\simpson_avatar.jpg");
    button.setIcon(icon);
    //button.setIcon(QIcon::fromTheme("face-smile"));

    button.show();

    return app.exec();
}
