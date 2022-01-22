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
signals:
private slots:
    void slotSaveDocument();
    void slotLoadDocument();
    void slotClearDocuments();
    void slotSideEditRefresh(QString);
};

#endif // TEXTWINDOW_H
