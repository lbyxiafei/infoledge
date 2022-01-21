#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QBoxLayout>
#include <QTextEdit>
#include <QWidget>


class QPushButton;
class MenuWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWindow(QWidget *parent = nullptr);
    QPushButton *button_save, *button_load, *button_format,
        *button_temp1, *button_clear, *button_quit;
private:
    QHBoxLayout *h_button_layout_;
signals:
private slots:
};

#endif // MENUWINDOW_H
