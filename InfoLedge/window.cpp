#include <QPushButton>

#include "window.h"

Window::Window(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(1000, 500);

    m_button=new QPushButton("ButtonText-Courier", this);
    m_button->setGeometry(10, 10, 500, 300);
    m_button->setToolTip("A tooltip");
    QFont font("Courier");
    m_button->setFont(font);
    QIcon icon("../InfoLedge/resources/avatar.jpg");
    m_button->setIcon(icon);
}
