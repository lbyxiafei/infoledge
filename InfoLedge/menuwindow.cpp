#include <bits/stdc++.h>
#include <QApplication>

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

    h_button_layout_ = new QHBoxLayout(this);

    // Button(s)
    button_save=new QPushButton("Save", this);
    button_save->setIcon(icon_avatar);
    h_button_layout_->addWidget(button_save);
    button_load=new QPushButton("Load", this);
    button_load->setIcon(icon_happy);
    h_button_layout_->addWidget(button_load);
    button_format=new QPushButton("Format", this);
    button_format->setIcon(icon_love);
    h_button_layout_->addWidget(button_format);
    button_temp1=new QPushButton("Temp1", this);
    button_temp1->setIcon(icon_smile);
    h_button_layout_->addWidget(button_temp1);
    button_clear=new QPushButton("Clear", this);
    button_clear->setIcon(icon_wow);
    h_button_layout_->addWidget(button_clear);
    button_quit=new QPushButton("Quit", this);
    button_quit->setIcon(icon_laugh);
    h_button_layout_->addWidget(button_quit);

    // Connect(s):
//    connect(button_save_, SIGNAL (clicked()), this, SLOT (slotSaveDocument()));
//    connect(button_load_, SIGNAL (clicked()), this, SLOT (slotLoadDocument()));
//    connect(button_clear_, SIGNAL (clicked()), this, SLOT (slotClearDocuments()));
//    connect(button_quit_, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
}
