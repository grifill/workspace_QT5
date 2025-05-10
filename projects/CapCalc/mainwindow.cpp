#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("QTableWidget Example");

    // =============================================
    QString logo = ":/companies_icos/companies/ico/BANE_512x512.png";

    QPixmap pixmap = QPixmap(logo);
    //int w = ui->company_ico->width();
    //int h = ui->company_ico->height();
    ui->company_ico->setPixmap(pixmap.scaled(128, 128, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //pixmap.scaled(10,10,Qt::IgnoreAspectRatio);
    //ui->company_ico->QLabel::setPixmap(pixmap);

    // ==============================================
    model = new CustomTable;
    //QTableView *tableView = new QTableView;
    //tableView->setModel(model);
    //tableView->setMinimumWidth(300);
    //tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //model->setParent(tableView);

    ui->tableViewMain->setModel(model);



}

MainWindow::~MainWindow()
{
    delete ui;
}

