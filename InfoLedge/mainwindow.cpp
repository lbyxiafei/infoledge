#include <QDebug>
#include <QSizePolicy>

#include "mainwindow.h"
#include "menuwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    m_gridLayout = new QGridLayout(this);

    m_menuWindow = new MenuWindow(this);
    qDebug()<<m_menuWindow->size();
    qDebug()<<m_menuWindow->sizeHint();
    qDebug()<<m_menuWindow->layout();
    qDebug()<<m_menuWindow->minimumSize();
    qDebug()<<m_menuWindow->minimumSizeHint();
    qDebug()<<m_menuWindow->sizePolicy();

    m_gridLayout->addWidget(m_menuWindow, 0,0,1,1);
}
