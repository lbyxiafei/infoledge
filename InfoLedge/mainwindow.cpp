#include <QApplication>
#include <QDebug>
#include <QPushButton>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    v_main_layout_ = new QVBoxLayout();
    central_widget_ = new QWidget(this);

    search_window_ = new SearchWindow(this);
    v_main_layout_->addWidget(search_window_);
    text_window_ = new TextWindow(this);
    v_main_layout_->addWidget(text_window_);

    central_widget_->setLayout(v_main_layout_);
    setCentralWidget(central_widget_);
}

void MainWindow::keyPressEvent(QKeyEvent* ke)
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "mw" << ke->key() << "down";
    if(ke->modifiers() & Qt::ControlModifier){
        if(ke->key()==Qt::Key_1){
            text_window_->slotDemoModeEnabled(true);
            search_window_->line_edit->setFocus();
        }
        else if(ke->key()==Qt::Key_2){
            text_window_->slotDemoModeEnabled(false);
        }
        else if(ke->key()==Qt::Key_S){
            text_window_->slotSave();
        }
        else if(ke->key()==Qt::Key_O){
            text_window_->slotLoad();
        }
        else if(ke->key()==Qt::Key_L){
            text_window_->slotClear();
            search_window_->slotClear();
        }
    }
    QMainWindow::keyPressEvent(ke); // base class implementation
}
