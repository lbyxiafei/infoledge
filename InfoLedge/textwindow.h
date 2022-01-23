#ifndef TEXTWINDOW_H
#define TEXTWINDOW_H

#include <QBoxLayout>
#include <QPlainTextEdit>
#include <QStackedWidget>
#include <QWidget>

#include <plaintextedit.h>

class TextWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TextWindow(QWidget *parent = nullptr);
    QHBoxLayout *h_text_layout_;
    QStackedWidget *stacked_widget;
    QTextEdit *text_edit_md_viewer;
    PlainTextEdit *text_edit;
private:
    bool demo_mode_on_;
signals:
public slots:
    void slotSave();
    void slotLoad();
    void slotClear();
    void slotDemoModeEnabled(bool);
};

#endif // TEXTWINDOW_H
