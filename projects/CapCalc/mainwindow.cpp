#include "mainwindow.h"
#include "company_preview_area.h"

MainWindow::MainWindow() {

    // 1. =========================================================
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 2. =========================================================
    createActions();

    // 3. Choise ==================================================
    QGridLayout *choiseLayout = new QGridLayout();
    QComboBox* choiseCompany = new QComboBox;
    QLabel* choiseCompanyName = new QLabel;
    choiseCompanyName->setText("Company Choise");
    choiseCompany->setMinimumSize(200,25);
    choiseCompany->setEditable(true);
    choiseCompany->lineEdit()->setReadOnly(true);
    choiseCompany->lineEdit()->setAlignment(Qt::AlignCenter);

    // Add Item Block
    choiseCompany->addItem("ПАО АНК «Башнефть»");
    choiseCompany->addItem("ПАО «НК Роснефть»");
    choiseCompany->addItem("ПАО «Сбербанк России»");
    choiseCompany->addItem("ПАО «Группа Аренадата»");

    // Add
    choiseLayout->addWidget(choiseCompanyName);
    choiseLayout->addWidget(choiseCompany);

    // 4. Preview =================================================
    CompanyPreviewData.nameCompany = "ПАО АНК «Башнефть»";
    CompanyPreviewData.logoPATH = ":/companies_icos/companies/ico/BANE_512x512.png";

    QGroupBox *previewGroupBox = new QGroupBox(tr("Company Preview"));
    previewComArea = new CompanyPreviewArea(previewGroupBox, &CompanyPreviewData);
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

    // 4. Signals & slots =======================================
    connect(choiseCompany, &QComboBox::currentTextChanged, this, &MainWindow::reprint);
    //connect(previewComArea, SIGNAL(infoDataChanged(&CompanyPreviewData)), this, SLOT(infoDataChange()));
    //connect(previewComArea, SIGNAL(reprint(const QString &)), SLOT(infoDataChange(const CompanyPreviewAreaInfo &)));

    // 5. Create Main Layout =======================================
    placeholderWidget = new QWidget;
    mainLayout = new QGridLayout(centralWidget);

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
    if (company == "ПАО «НК Роснефть»") {
        qDebug("ROSN");
        CompanyPreviewData.nameCompany = "ПАО «НК Роснефть»";
        CompanyPreviewData.logoPATH = ":/companies_icos/companies/ico/ROSN_512x512.png";
        previewComArea->infoDataChange(&CompanyPreviewData);
    }
    if (company == "ПАО АНК «Башнефть»") {
        qDebug("BANE");
        CompanyPreviewData.nameCompany = "ПАО АНК «Башнефть»";
        CompanyPreviewData.logoPATH = ":/companies_icos/companies/ico/BANE_512x512.png";
        previewComArea->infoDataChange(&CompanyPreviewData);
    }
    if (company == "ПАО «Сбербанк России»") {
        qDebug("SBER");
        CompanyPreviewData.nameCompany = "ПАО «Сбербанк России»";
        CompanyPreviewData.logoPATH = ":/companies_icos/companies/ico/SBER_512x512.png";
        previewComArea->infoDataChange(&CompanyPreviewData);
    }
    if (company == "ПАО «Группа Аренадата»") {
        qDebug("DATA");
        CompanyPreviewData.nameCompany = "ПАО «Группа Аренадата»";
        CompanyPreviewData.logoPATH = ":/companies_icos/companies/ico/DATA_512x512.png";
        previewComArea->infoDataChange(&CompanyPreviewData);
    }
    qApp->processEvents();
}
