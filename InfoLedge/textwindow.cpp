#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

#include "textwindow.h"

TextWindow::TextWindow(QWidget *parent)
    : QWidget{parent}
{
    h_text_layout_ = new QHBoxLayout();

    text_edit=new QTextEdit(this);
    h_text_layout_->addWidget(text_edit);
    text_edit_side=new QTextEdit(this);
    h_text_layout_->addWidget(text_edit_side);

    setLayout(h_text_layout_);
}

void TextWindow::slotSaveDocument(){
    QTextDocument *edit_doc = text_edit->document();
    QString file_name = QFileDialog::getSaveFileName(this,
            tr("Save Text"), "",
            tr("Text (*.txt);;All Files (*)"));
    if (file_name.isEmpty()) return;
    else {
        QFile file(file_name);
        if (!file.open(QIODevice::WriteOnly)) {
           QMessageBox::information(this, tr("Unable to open file"),
               file.errorString());
           return;
        }
        file.write(edit_doc->toRawText().toUtf8());
        file.close();
    }
    return;
}

void TextWindow::slotLoadDocument(){
    QString file_name = QFileDialog::getOpenFileName(this,
            tr("Save Text"), "",
            tr("Text (*.txt);;All Files (*)"));
    if (file_name.isEmpty()) return;
    else {
        QFile file(file_name);
        if (!file.open(QFile::ReadOnly)) {
           QMessageBox::information(this, tr("Unable to open file"),
               file.errorString());
           return;
        }
        QString file_content_in_str = QString::fromUtf8(file.readAll());
        text_edit->setPlainText(file_content_in_str);
        file.close();
    }
}

void TextWindow::slotClearDocuments(){
    text_edit->clear();
    text_edit_side->clear();
}

void TextWindow::slotSideEditRefresh(QString content_in_str){
    text_edit_side->setPlainText(content_in_str);
}
