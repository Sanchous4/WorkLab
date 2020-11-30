#include <QApplication>
#include <QDebug>

#include <collections_chng.h>
#include <mainwindow.h>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    main_window w;
    w.show();
    return a.exec();
}
