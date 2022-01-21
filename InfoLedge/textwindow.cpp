#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

#include "textwindow.h"

TextWindow::TextWindow(QWidget *parent)
    : QWidget{parent}
{
    h_text_layout_ = new QHBoxLayout(this);

    text_edit=new QTextEdit(this);
    h_text_layout_->addWidget(text_edit);

    text_edit_side=new QTextEdit(this);
    h_text_layout_->addWidget(text_edit_side);
}

void TextWindow::slotSaveDocument(){
    QTextDocument *qTextDocument = text_edit->document();
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Text"), "",
            tr("Text (*.txt);;All Files (*)"));
    if (fileName.isEmpty()) return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
           QMessageBox::information(this, tr("Unable to open file"),
               file.errorString());
           return;
        }
        file.write(qTextDocument->toRawText().toUtf8());
        file.close();
    }
    return;
}

void TextWindow::slotLoadDocument(){
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Save Text"), "",
            tr("Text (*.txt);;All Files (*)"));
    if (fileName.isEmpty()) return;
    else {
        QFile file(fileName);
        if (!file.open(QFile::ReadOnly)) {
           QMessageBox::information(this, tr("Unable to open file"),
               file.errorString());
           return;
        }
        QString qStringContent = QString::fromUtf8(file.readAll());
        text_edit->setPlainText(qStringContent);
        file.close();
    }
}

void TextWindow::slotClearDocuments(){
    text_edit->clear();
    text_edit_side->clear();
}
