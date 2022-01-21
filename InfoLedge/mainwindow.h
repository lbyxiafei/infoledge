#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QMainWindow>

#include "menuwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private:
    QGridLayout *m_gridLayout;
    MenuWindow *m_menuWindow;

signals:

};

#endif // MAINWINDOW_H
