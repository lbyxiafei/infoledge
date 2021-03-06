#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QBoxLayout>
#include <QMainWindow>

#include "searchwindow.h"
#include "textwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual void keyPressEvent(QKeyEvent*);
private:
    QWidget *central_widget_;
    QVBoxLayout *v_main_layout_;
    SearchWindow *search_window_;
    TextWindow *text_window_;
signals:
private slots:
};

#endif // MAINWINDOW_H
