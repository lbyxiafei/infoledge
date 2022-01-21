#include <bits/stdc++.h>
#include <QApplication>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>

#include "menuwindow.h"

using namespace std;

MenuWindow::MenuWindow(QWidget *parent)
    : QWidget{parent}
{
    QIcon icon_avatar("../InfoLedge/resources/emoji/avatar.jpg");
    QIcon icon_happy("../InfoLedge/resources/emoji/happy.png");
    QIcon icon_love("../InfoLedge/resources/emoji/love.png");
    QIcon icon_smile("../InfoLedge/resources/emoji/smile.png");
    QIcon icon_wow("../InfoLedge/resources/emoji/wow.png");
    QIcon icon_laugh("../InfoLedge/resources/emoji/laugh.png");

    button_cnt_=0;

    // Layouts
    v_box_layout_ = new QVBoxLayout(this);
    h_button_layout_ = new QHBoxLayout();
    h_search_layout_ = new QHBoxLayout();
    h_text_layout_ = new QHBoxLayout();

    v_box_layout_->addLayout(h_button_layout_);
    v_box_layout_->addLayout(h_search_layout_);
    v_box_layout_->addLayout(h_text_layout_);

    // Button(s)
    button_save_=new QPushButton("Save", this);
    button_save_->setIcon(icon_avatar);
    h_button_layout_->addWidget(button_save_);
    button_load_=new QPushButton("Load", this);
    button_load_->setIcon(icon_happy);
    h_button_layout_->addWidget(button_load_);
    button_format_=new QPushButton("Format", this);
    button_format_->setIcon(icon_love);
    h_button_layout_->addWidget(button_format_);
    button_temp1_=new QPushButton("Temp1", this);
    button_temp1_->setIcon(icon_smile);
    h_button_layout_->addWidget(button_temp1_);
    button_clear_=new QPushButton("Clear", this);
    button_clear_->setIcon(icon_wow);
    h_button_layout_->addWidget(button_clear_);
    button_quit_=new QPushButton("Quit", this);
    button_quit_->setIcon(icon_laugh);
    h_button_layout_->addWidget(button_quit_);

    // LineEdit(s)
    line_edit_=new QLineEdit(this);
    h_search_layout_->addWidget(line_edit_);

    // TextEdit(s)
    text_edit_=new QTextEdit(this);
    h_text_layout_->addWidget(text_edit_);

    text_edit_side_=new QTextEdit(this);
    h_text_layout_->addWidget(text_edit_side_);

    // Connect(s):
    connect(button_save_, SIGNAL (clicked()), this, SLOT (slotSaveDocument()));
    connect(button_load_, SIGNAL (clicked()), this, SLOT (slotLoadDocument()));
    connect(button_clear_, SIGNAL (clicked()), this, SLOT (slotClearDocuments()));
    connect(button_quit_, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
}

void MenuWindow::slotSaveDocument(){
    QTextDocument *qTextDocument = text_edit_->document();
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

void MenuWindow::slotLoadDocument(){
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
        text_edit_->setPlainText(qStringContent);
        file.close();
    }
}

void MenuWindow::slotClearDocuments(){
    text_edit_->clear();
    text_edit_side_->clear();
}
