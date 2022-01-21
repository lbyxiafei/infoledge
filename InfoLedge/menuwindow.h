#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QLineEdit>
#include <QBoxLayout>
#include <QTextEdit>
#include <QWidget>


class QPushButton;
class MenuWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWindow(QWidget *parent = nullptr);
private:
    int button_cnt_;

    QVBoxLayout *v_box_layout_;
    QHBoxLayout *h_button_layout_, *h_search_layout_, *h_text_layout_;
    QPushButton *button_save_, *button_load_, *button_format_,
        *button_temp1_, *button_clear_, *button_quit_;
    QLineEdit *line_edit_;
    QTextEdit *text_edit_, *text_edit_side_;

signals:
private slots:
    void slotSaveDocument();
    void slotLoadDocument();
    void slotClearDocuments();
};

#endif // MENUWINDOW_H
