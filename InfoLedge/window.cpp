#include <bits/stdc++.h>
#include <QPushButton>
#include <QApplication>
#include <QFile>

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

    m_buttonSave=new QPushButton("Save", this);
    m_buttonQuit=new QPushButton("Quit", this);

    QIcon icon_avatar("../InfoLedge/resources/emoji/avatar.jpg");
    m_buttonSave->setIcon(icon_avatar);
    m_buttonSave->setGeometry(m_margin,m_margin,
                              m_buttonWidth,m_buttonHeight);

    QIcon icon_door("../InfoLedge/resources/emoji/laugh.png");
    m_buttonQuit->setIcon(icon_door);
    m_buttonQuit->setGeometry(m_margin+m_buttonWidth,m_margin,
                              m_buttonWidth,m_buttonHeight);

    // Connects:
    connect(m_buttonSave, SIGNAL (clicked()), this, SLOT (slotSaveDocument()));
    connect(m_buttonQuit, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
}

void Window::saveDocument(const QString& qStr){
    QString path= QCoreApplication::applicationDirPath() + QString("/test.txt");
    cout << path.toStdString() << endl;
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        file.close();
    } else {
        QTextStream out(&file);
        out << qStr;
        file.close();
    }
}

void Window::slotSaveDocument(){
    QTextDocument *qTextDocument = m_textEdit->document();
    QString qPlainText = qTextDocument->toPlainText();
    saveDocument(qPlainText);
    cout << qPlainText.toStdString() << endl;
    return;
}
