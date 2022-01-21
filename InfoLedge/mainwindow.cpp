#include <QApplication>
#include <QDebug>
#include <QPushButton>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    v_main_layout_ = new QVBoxLayout();
    central_widget_ = new QWidget(this);

    menu_window_ = new MenuWindow(this);
    v_main_layout_->addWidget(menu_window_);
    search_window_ = new SearchWindow(this);
    v_main_layout_->addWidget(search_window_);
    text_window_ = new TextWindow(this);
    v_main_layout_->addWidget(text_window_);

    // Connect(s):
    connect(menu_window_->button_save, SIGNAL (clicked()),
            text_window_, SLOT (slotSaveDocument()));
    connect(menu_window_->button_load, SIGNAL (clicked()),
            text_window_, SLOT (slotLoadDocument()));
    connect(menu_window_->button_clear, SIGNAL (clicked()),
            text_window_, SLOT (slotClearDocuments()));
    connect(menu_window_->button_quit, SIGNAL (clicked()),
            QApplication::instance(), SLOT (quit()));

    central_widget_->setLayout(v_main_layout_);
    setCentralWidget(central_widget_);
}
