#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTextEdit>

class QPushButton;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
private:
    QPushButton *m_buttonSave, *m_buttonLoad, *m_buttonFormat,
        *m_buttonTemp1, *m_buttonTemp2, *m_buttonQuit;
    QTextEdit *m_textEdit;
signals:
private slots:
    void slotSaveDocument();
};

#endif // WINDOW_H
