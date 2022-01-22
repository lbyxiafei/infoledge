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
    QPushButton *button_mode, *button_save, *button_load,
        *button_temp1, *button_clear, *button_quit;
private:
    bool edit_mode_on_;
    QHBoxLayout *h_button_layout_;
signals:
private slots:
    void slotModeChanged(bool);
};

#endif // MENUWINDOW_H
