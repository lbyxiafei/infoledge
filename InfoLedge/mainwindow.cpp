#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    central_widget_ = new QWidget(this);
    v_main_layout_ = new QVBoxLayout();
    central_widget_->setLayout(v_main_layout_);

    menu_window_ = new MenuWindow(this);
    v_main_layout_->addWidget(menu_window_);

    search_window_ = new SearchWindow(this);
    v_main_layout_->addWidget(search_window_);

    text_window_ = new TextWindow(this);
    v_main_layout_->addWidget(text_window_);

    setCentralWidget(central_widget_);
}
