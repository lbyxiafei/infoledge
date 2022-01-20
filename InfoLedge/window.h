#ifndef WINDOW_H
#define WINDOW_H

#include <QLineEdit>
#include <QTextEdit>
#include <QWidget>


class QPushButton;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
private:
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

#endif // WINDOW_H
