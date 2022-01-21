#include "searchwindow.h"

SearchWindow::SearchWindow(QWidget *parent)
    : QWidget{parent}
{
    h_search_layout_ = new QHBoxLayout();

    line_edit=new QLineEdit(this);
    h_search_layout_->addWidget(line_edit);

    setLayout(h_search_layout_);
}
