#include <bits/stdc++.h>
#include <QPushButton>
#include <QApplication>

#include "window.h"

using namespace std;

Window::Window(QWidget *parent)
    : QWidget{parent}
{
    m_margin=10;
    m_buttonWidth=80, m_buttonHeight=30;
    m_textWidth=1000, m_textHeight=600;

    m_textEdit=new QTextEdit(this);
    m_textEdit->setGeometry(m_margin, m_margin+m_buttonHeight,
                            m_textWidth, m_textHeight);

    m_buttonInfo=new QPushButton("Info", this);
    m_buttonQuit=new QPushButton("Quit", this);

    QIcon icon_avatar("../InfoLedge/resources/emoji/avatar.jpg");
    m_buttonInfo->setIcon(icon_avatar);
    m_buttonInfo->setGeometry(m_margin,m_margin,
                              m_buttonWidth,m_buttonHeight);

    QIcon icon_door("../InfoLedge/resources/emoji/laugh.png");
    m_buttonQuit->setIcon(icon_door);
    m_buttonQuit->setGeometry(m_margin+m_buttonWidth,m_margin,
                              m_buttonWidth,m_buttonHeight);

    // Connects:
    connect(m_buttonInfo, SIGNAL (clicked()), QApplication::instance(), SLOT (aboutQt()));
    connect(m_buttonQuit, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
}
