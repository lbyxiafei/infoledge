#include <bits/stdc++.h>
#include <QApplication>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>

#include "window.h"

using namespace std;

Window::Window(QWidget *parent)
    : QWidget{parent}
{
    int margin=10;
    int buttonWidth=80, buttonHeight=30, buttonCnt=0;
    int textWidth=500, textHeight=600;

    QIcon icon_avatar("../InfoLedge/resources/emoji/avatar.jpg");
    QIcon icon_happy("../InfoLedge/resources/emoji/happy.png");
    QIcon icon_love("../InfoLedge/resources/emoji/love.png");
    QIcon icon_smile("../InfoLedge/resources/emoji/smile.png");
    QIcon icon_wow("../InfoLedge/resources/emoji/wow.png");
    QIcon icon_laugh("../InfoLedge/resources/emoji/laugh.png");

    // Button(s)
    m_buttonSave=new QPushButton("Save", this);
    m_buttonSave->setIcon(icon_avatar);
    m_buttonSave->setGeometry(margin+buttonWidth*buttonCnt++,margin,
                              buttonWidth,buttonHeight);
    m_buttonLoad=new QPushButton("Load", this);
    m_buttonLoad->setIcon(icon_happy);
    m_buttonLoad->setGeometry(margin+buttonWidth*buttonCnt++,margin,
                              buttonWidth,buttonHeight);
    m_buttonFormat=new QPushButton("Format", this);
    m_buttonFormat->setIcon(icon_love);
    m_buttonFormat->setGeometry(margin+buttonWidth*buttonCnt++,margin,
                              buttonWidth,buttonHeight);
    m_buttonTemp1=new QPushButton("Temp1", this);
    m_buttonTemp1->setIcon(icon_smile);
    m_buttonTemp1->setGeometry(margin+buttonWidth*buttonCnt++,margin,
                              buttonWidth,buttonHeight);
    m_buttonClear=new QPushButton("Clear", this);
    m_buttonClear->setIcon(icon_wow);
    m_buttonClear->setGeometry(margin+buttonWidth*buttonCnt++,margin,
                              buttonWidth,buttonHeight);
    m_buttonQuit=new QPushButton("Quit", this);
    m_buttonQuit->setIcon(icon_laugh);
    m_buttonQuit->setGeometry(margin+buttonWidth*buttonCnt++,margin,
                              buttonWidth,buttonHeight);

    // LineEdit(s)
    m_lineEdit=new QLineEdit(this);

    // TextEdit(s)
    m_textEdit=new QTextEdit(this);
    m_textEdit->setGeometry(margin, margin+buttonHeight,
                            textWidth, textHeight);
    m_textEditSide=new QTextEdit(this);
    m_textEditSide->setGeometry(margin+textWidth, margin+buttonHeight,
                            textWidth, textHeight);

    // Connect(s):
    connect(m_buttonSave, SIGNAL (clicked()), this, SLOT (slotSaveDocument()));
    connect(m_buttonLoad, SIGNAL (clicked()), this, SLOT (slotLoadDocument()));
    connect(m_buttonClear, SIGNAL (clicked()), this, SLOT (slotClearDocuments()));
    connect(m_buttonQuit, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
}

void Window::slotSaveDocument(){
    QTextDocument *qTextDocument = m_textEdit->document();
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Text"), "",
            tr("Text (*.txt);;All Files (*)"));
    if (fileName.isEmpty()) return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
           QMessageBox::information(this, tr("Unable to open file"),
               file.errorString());
           return;
        }
        file.write(qTextDocument->toRawText().toUtf8());
        file.close();
    }
    return;
}

void Window::slotLoadDocument(){
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Save Text"), "",
            tr("Text (*.txt);;All Files (*)"));
    if (fileName.isEmpty()) return;
    else {
        QFile file(fileName);
        if (!file.open(QFile::ReadOnly)) {
           QMessageBox::information(this, tr("Unable to open file"),
               file.errorString());
           return;
        }
        QString qStringContent = QString::fromUtf8(file.readAll());
        m_textEdit->setPlainText(qStringContent);
        file.close();
    }
}

void Window::slotClearDocuments(){
    m_textEdit->clear();
    m_textEditSide->clear();
}
