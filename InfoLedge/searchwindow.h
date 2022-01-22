#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>

class SearchWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SearchWindow(QWidget *parent = nullptr);
    QLineEdit *line_edit;
private:
    bool edit_mode_on_;
    QFormLayout *form_layout_;
signals:
private slots:
    void slotClear();
    void slotModeChanged(bool);
};

#endif // SEARCHWINDOW_H
