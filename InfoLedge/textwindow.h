#ifndef TEXTWINDOW_H
#define TEXTWINDOW_H

#include <QBoxLayout>
#include <QTextEdit>
#include <QWidget>

class TextWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TextWindow(QWidget *parent = nullptr);
    QHBoxLayout *h_text_layout_;
    QTextEdit *text_edit, *text_edit_side;
private:
    bool edit_mode_on_;
signals:
private slots:
    void slotSaveDocument();
    void slotLoadDocument();
    void slotClear();
    void slotSideEditRefresh(QString);
    void slotModeChanged(bool);
};

#endif // TEXTWINDOW_H
