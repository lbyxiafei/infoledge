#include <QDebug>
#include <QSizePolicy>

#include "mainwindow.h"
#include "menuwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    central_widget_ = new QWidget();
    grid_layout_ = new QGridLayout();
    central_widget_->setLayout(grid_layout_);

    menu_window_ = new MenuWindow(this);
    grid_layout_->addWidget(menu_window_,0,0);

    setCentralWidget(central_widget_);
}
