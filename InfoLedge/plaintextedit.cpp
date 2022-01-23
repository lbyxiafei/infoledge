#include "plaintextedit.h"

PlainTextEdit::PlainTextEdit(QWidget *parent)
    : QPlainTextEdit{parent}
{
}

void PlainTextEdit::keyPressEvent(QKeyEvent *e){
    if(e->key()==Qt::Key_Tab){
        e = new QKeyEvent(QEvent::KeyPress, Qt::Key_Space,
                          Qt::KeyboardModifiers(e->nativeModifiers()),
                          "    ");
    }
    QPlainTextEdit::keyPressEvent(e);
}
