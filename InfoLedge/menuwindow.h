#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QLineEdit>
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

    QPushButton *m_buttonSave, *m_buttonLoad, *m_buttonFormat,
        *m_buttonTemp1, *m_buttonClear, *m_buttonQuit;
    QLineEdit *m_lineEdit;
    QTextEdit *m_textEdit, *m_textEditSide;
signals:
private slots:
    void slotSaveDocument();
    void slotLoadDocument();
    void slotClearDocuments();
};

#endif // MENUWINDOW_H
