#include "mainwindow.h"
#include "company_preview_area.h"

MainWindow::MainWindow() {

    // 1. -----
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 2. -----
    createActions();

    // 3. -----
    // Choise ============================================================================
    QComboBox* choiseCompany = new QComboBox;
    QLabel* choiseCompanyName = new QLabel;
    QFrame* choiseCompanyFrame = new QFrame;
    choiseCompanyFrame->setFrameShape(QFrame::Box);
    choiseCompanyFrame->setMinimumSize(200,20);
    choiseCompanyName->setText("Company Choise");
    choiseCompany->addItem("BANE");
    choiseCompany->addItem("LKOH");

    connect(choiseCompany, &QComboBox::currentTextChanged, this, &MainWindow::reprint);


    // 4. -----
    CompanyPreviewAreaInfo data;
    data.nameCompany = "PJSC ANC Bashneft";
    data.logoPATH = ":/companies_icos/companies/ico/BANE_512x512.png";

    // 5. -----
    QGroupBox *previewGroupBox = new QGroupBox(tr("Company Preview"));
    previewComArea = new CompanyPreviewArea(previewGroupBox, &data);
    QVBoxLayout *previewLayout = new QVBoxLayout(previewGroupBox);
    previewGroupBox->setMinimumSize(300,600);
    previewLayout->addWidget(previewComArea);

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
    QGridLayout *choiseLayout = new QGridLayout();

    choiseLayout->addWidget(choiseCompanyFrame);
    choiseLayout->addWidget(choiseCompanyName, 0, 0, Qt::AlignLeft | Qt::AlignVCenter);
    choiseLayout->addWidget(choiseCompany, 0, 0, Qt::AlignRight | Qt::AlignVCenter);

    mainLayout->addLayout(choiseLayout, 0, 0, Qt::AlignLeft | Qt::AlignTop);
    mainLayout->addWidget(previewGroupBox, 1, 0, Qt::AlignHCenter | Qt::AlignTop);
    mainLayout->addWidget(tableView, 1, 1);
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

void MainWindow::reprint(const QString &company) {
    if (company == "LKOH") {
        qDebug("LKOH");
    }
}
