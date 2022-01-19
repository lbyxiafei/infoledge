#include <bits/stdc++.h>
#include <QPushButton>
#include <QApplication>

#include "window.h"

using namespace std;

Window::Window(QWidget *parent)
    : QWidget{parent}
{
    m_counter=0;
//    setFixedSize(1000, 500);

    m_button=new QPushButton(this);

    m_button->setText("Hello world!");
    m_button->setToolTip("A tooltip");
    m_button->setGeometry(10, 10, 500, 300);

    QFont font("Courier");
    m_button->setFont(font);

    QIcon icon("../InfoLedge/resources/avatar.jpg");
    m_button->setIcon(icon);

    m_button->setCheckable(true);

    // Connects:
    connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
    connect(this, SIGNAL (counterReached()), QApplication::instance(), SLOT (quit()));
}

void Window::slotButtonClicked(bool checked){
    if(checked){
        m_button->setText("Yo~");
    }
    else{
        m_button->setText("Sup!");
    }

    m_counter++;
//    cout << m_counter << endl;
    if(m_counter==10){
        emit counterReached();
    }
}
