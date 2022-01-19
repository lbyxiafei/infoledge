#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

private:
    int m_counter;
    QPushButton *m_button;

signals:
    void counterReached();

private slots:
    void slotButtonClicked(bool);
};

#endif // WINDOW_H
