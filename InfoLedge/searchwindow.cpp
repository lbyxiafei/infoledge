#include <QCompleter>
#include <QIcon>
#include <QLabel>

#include "searchwindow.h"

SearchWindow::SearchWindow(QWidget *parent)
    : QWidget{parent}
{
    form_layout_ = new QFormLayout();
    edit_mode_on_=false;

    QIcon icon_avatar("../InfoLedge/resources/emoji/avatar.jpg");
    QLabel *label_avatar=new QLabel();
    label_avatar->setPixmap(icon_avatar.pixmap(23,23));

    line_edit=new QLineEdit(this);
    form_layout_->addRow(label_avatar, line_edit);

    QStringList wordList;
    wordList << "alpha" << "omega" << "omicron" << "zeta";
    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    line_edit->setCompleter(completer);

    setLayout(form_layout_);
}

void SearchWindow::slotClear(){
    line_edit->clear();
}

void SearchWindow::slotModeChanged(bool button_mode_checked){
    edit_mode_on_=button_mode_checked;
    if(!edit_mode_on_) line_edit->clear();
}
