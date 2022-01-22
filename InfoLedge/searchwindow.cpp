#include "searchwindow.h"

SearchWindow::SearchWindow(QWidget *parent)
    : QWidget{parent}
{
    form_layout_ = new QFormLayout();

    line_edit=new QLineEdit(this);
    form_layout_->addRow(tr("&Search:"), line_edit);

    setLayout(form_layout_);
}
