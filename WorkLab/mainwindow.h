#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "collections_chng.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class main_window : public QMainWindow {
    Q_OBJECT

public:
    main_window(QWidget* parent = nullptr);
    ~main_window();

private slots:
    void on_textEdit_textChanged();
    void on_undoButton_clicked();
    void on_redoButton_clicked();

private:
    Ui::MainWindow* ui;
    collections_chng m_textEditor;
};
#endif // MAINWINDOW_H
