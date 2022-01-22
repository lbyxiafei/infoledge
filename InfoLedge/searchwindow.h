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
    QFormLayout *form_layout_;
signals:
private slots:
};

#endif // SEARCHWINDOW_H
