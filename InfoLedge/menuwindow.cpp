#include <bits/stdc++.h>
#include <QPushButton>

#include "menuwindow.h"

using namespace std;

MenuWindow::MenuWindow(QWidget *parent)
    : QWidget{parent}
{
    h_button_layout_ = new QHBoxLayout();
    edit_mode_on_=false;

    QIcon icon_working("../InfoLedge/resources/emoji/winking-face.png");
    QIcon icon_happy("../InfoLedge/resources/emoji/happy.png");
    QIcon icon_love("../InfoLedge/resources/emoji/love.png");
    QIcon icon_smile("../InfoLedge/resources/emoji/smile.png");
    QIcon icon_wow("../InfoLedge/resources/emoji/wow.png");
    QIcon icon_laugh("../InfoLedge/resources/emoji/laugh.png");

    // Button(s)
    button_mode=new QPushButton("Demo", this);
    button_mode->setIcon(icon_working);
    button_mode->setCheckable(true);
    h_button_layout_->addWidget(button_mode);
    button_save=new QPushButton("Save", this);
    button_save->setIcon(icon_love);
    h_button_layout_->addWidget(button_save);
    button_load=new QPushButton("Load", this);
    button_load->setIcon(icon_happy);
    h_button_layout_->addWidget(button_load);
    button_temp1=new QPushButton("Temp1", this);
    button_temp1->setIcon(icon_smile);
    h_button_layout_->addWidget(button_temp1);
    button_clear=new QPushButton("Clear", this);
    button_clear->setIcon(icon_wow);
    h_button_layout_->addWidget(button_clear);
    button_quit=new QPushButton("Quit", this);
    button_quit->setIcon(icon_laugh);
    h_button_layout_->addWidget(button_quit);

    setLayout(h_button_layout_);
}

void MenuWindow::slotModeChanged(bool button_mode_checked){
    edit_mode_on_=button_mode_checked;
    if(edit_mode_on_) button_mode->setText("Edit");
    else button_mode->setText("Demo");
}
