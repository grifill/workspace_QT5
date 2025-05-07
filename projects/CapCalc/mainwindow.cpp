#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("QTableWidget Example");

   /* QPixmap pixmap = QPixmap(":/companies_icos/companies/ico/BANE_512x512.png");
    int w = ui->company_ico->width();
    int h = ui->company_ico->height();
    ui->company_ico->setPixmap(pixmap.scaled (w,h,Qt::KeepAspectRatio));

    //pixmap.scaled(10,10,Qt::IgnoreAspectRatio);
    //ui->company_ico->QLabel::setPixmap(pixmap);*/


}

MainWindow::~MainWindow()
{
    delete ui;
}

