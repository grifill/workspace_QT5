#include "mainwindow.h"
#include "company_preview_area.h"

MainWindow::MainWindow() {

    // 1. -----
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 2. -----
    createActions();

    // 3. -----
    QGroupBox *previewGroupBox = new QGroupBox(tr("Company preview"));
    previewComArea = new CompanyPreviewArea(previewGroupBox);
    QVBoxLayout *previewLayout = new QVBoxLayout(previewGroupBox);
    previewLayout->addWidget(previewComArea);


    // =============================================
    QString logo = ":/companies_icos/companies/ico/BANE_512x512.png";
    QPixmap pixmap = QPixmap(logo);
    // =============================================

    // Интерфейс
    QLabel *ico = new QLabel(this);
    ico->setAlignment(Qt::AlignmentFlag::AlignCenter);
    ico->setStyleSheet("QLabel {"
                                 "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: black; "
                                 "}");
    //ico->setText("lskdf;lsdkf;lk");
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
    QGridLayout *mainLayout = new QGridLayout(centralWidget);
    mainLayout->addWidget(previewGroupBox, 1, 0);
    mainLayout->addWidget(ico, 1, 1);
    mainLayout->addWidget(tableView, 1, 2);
    mainLayout->setColumnStretch(1, 1);
    mainLayout->setColumnStretch(0, 0);
    placeholderWidget->setLayout(mainLayout);
    setCentralWidget(placeholderWidget);
}

void MainWindow::createActions() {
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *exitAct = fileMenu->addAction(tr("&Quit"), this, &QWidget::close);
    exitAct->setShortcuts(QKeySequence::Quit);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(tr("&About"), this, &MainWindow::about);
}

void MainWindow::show() {
    QMainWindow::show();
}

void MainWindow::about() {
    QMessageBox::about(this, tr("About CapCalc"),
            tr("The <b>CapCalc</b> example"));
}

