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
    int m_margin, m_buttonWidth, m_buttonHeight, m_textWidth, m_textHeight;
    QPushButton *m_buttonSave, *m_buttonQuit;
    QTextEdit *m_textEdit;

    void saveDocument(const QString& qStr);
signals:
private slots:
    void slotSaveDocument();
};

#endif // WINDOW_H
