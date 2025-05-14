#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("CapCalc");

    // =============================================
    QString logo = ":/companies_icos/companies/ico/BANE_512x512.png";
    QPixmap pixmap = QPixmap(logo);
    // =============================================

    // Интерфейс
    QLabel *ico = new QLabel(this);
    ico->setAlignment(Qt::AlignmentFlag::AlignCenter);
    ico->setPixmap(pixmap.scaled(128, 128, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // ==============================================
    model = new CustomTable;
    QTableView *tableView = new QTableView;
    tableView->setModel(model);
    tableView->setMinimumWidth(300);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model->setParent(tableView);

    // Create main layout -----------------------------
    QWidget *placeholderWidget = new QWidget;
    QGridLayout *sainLayout = new QGridLayout;
    sainLayout->addWidget(ico, 1, 0);
    sainLayout->addWidget(tableView, 1, 1);
    sainLayout->setColumnStretch(1, 1);
    sainLayout->setColumnStretch(0, 0);
    placeholderWidget->setLayout(sainLayout);
    setCentralWidget(placeholderWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

