#include "mainwindow.h"
#include "ui_mainwindow.h"

main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

main_window::~main_window() {
    delete ui;
}

void main_window::on_textEdit_textChanged() {
    m_textEditor.supersede(ui->textEdit->toPlainText().toStdString(), 0, m_textEditor.text().length());
}

void main_window::on_undoButton_clicked() {
    m_textEditor.undo();
    ui->textEdit->blockSignals(true);
    ui->textEdit->setPlainText(m_textEditor.text().c_str());
    ui->textEdit->blockSignals(false);
}

void main_window::on_redoButton_clicked() {
    m_textEditor.redo();
    ui->textEdit->blockSignals(true);
    ui->textEdit->setPlainText(m_textEditor.text().c_str());
    ui->textEdit->blockSignals(false);
}
