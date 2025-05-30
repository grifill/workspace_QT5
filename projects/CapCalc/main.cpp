#include <QApplication>
#include <QCommandLineParser>
#include <QDesktopWidget>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName(MainWindow::tr("CapCalc"));
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    MainWindow w;
    const QRect availableGeometry = QApplication::desktop()->availableGeometry(&w);
    w.resize(availableGeometry.width() / 2, availableGeometry.height() * 2 / 3);
    w.move((availableGeometry.width() - w.width()) / 2, (availableGeometry.height() - w.height()) / 2);
    w.show();

    return app.exec();
}
