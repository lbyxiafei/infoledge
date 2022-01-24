#include <QFile>
#include <QFileDialog>
#include <QFontMetricsF>
#include <QMessageBox>

#include "textwindow.h"

TextWindow::TextWindow(QWidget *parent)
    : QWidget{parent}
{
    h_text_layout_ = new QHBoxLayout();
    demo_mode_on_=false;

    text_edit=new PlainTextEdit(this);
    text_edit_md_viewer=new QTextEdit(this);
    text_edit_md_viewer->setReadOnly(true);
    stacked_widget = new QStackedWidget(this);
    stacked_widget->addWidget(text_edit);
    stacked_widget->addWidget(text_edit_md_viewer);
    stacked_widget->setCurrentWidget(text_edit_md_viewer);
    h_text_layout_->addWidget(stacked_widget);

    setLayout(h_text_layout_);
}

QSize TextWindow::sizeHint() const {
    return QSize(550,500);
}

void TextWindow::slotSave(){
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

void TextWindow::slotLoad(){
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
        text_edit_md_viewer->setMarkdown(file_content_in_str);
        file.close();
    }
}

void TextWindow::slotClear(){
    text_edit->clear();
    text_edit_md_viewer->clear();
}

void TextWindow::slotDemoModeEnabled(bool demo_mode_on){
    demo_mode_on_=demo_mode_on;
    if(demo_mode_on_){
        text_edit_md_viewer->setMarkdown(text_edit->toPlainText());
        stacked_widget->setCurrentWidget(text_edit_md_viewer);
    }
    else{
        stacked_widget->setCurrentWidget(text_edit);
        text_edit->setFocus();
    }
}
