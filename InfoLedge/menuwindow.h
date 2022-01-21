#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QLineEdit>
#include <QGridLayout>
#include <QTextEdit>
#include <QWidget>


class QPushButton;
class MenuWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWindow(QWidget *parent = nullptr);
private:
    int margin_, button_width_, button_height_, button_cnt_;

    QGridLayout *grid_layout_;
    QPushButton *button_save_, *button_load_, *button_format_,
        *button_temp1_, *button_clear_, *button_quit_;
    QLineEdit *line_edit_;
    QTextEdit *text_edit_, *text_edit_side;

signals:
private slots:
    void slotSaveDocument();
    void slotLoadDocument();
    void slotClearDocuments();
};

#endif // MENUWINDOW_H
