/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2025 Gregory Filatov
 * All rights reserved.
 *
 * \file   mainwindow.cpp
 * \author Gregory Filatov
 * \date   30 May 2025
 * \version 1.0
 *
 * \brief  Contains main - mainwindow
 *
 * Module: mainwindow.cpp
 *
 * Purpose: Mainwindow - file
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */
#include "mainwindow.h"
#include "companyPreviewArea.h"

MainWindow::~MainWindow()
{
    //delete placeholderWidget;
    //delete mainLayout;
}


MainWindow::MainWindow() {

    // Language Settings
    setlocale(LC_ALL, "");
    QTextCodec *codecINI = QTextCodec::codecForName("utf-8");

    // Directory settings
    const QString dirINI = ":/companies_datas/companies/ini";
    const QString defaultINI = "BANE.ini";

    // Default values (on start)
    // Default Settings
    QSettings companyDefault(dirINI + "/" + defaultINI, QSettings::IniFormat);
    companyDefault.setIniCodec(codecINI);

    // Main
    companyDefault.beginGroup("main_info");
    CompanyPreviewData.nameCompany = companyDefault.value("name", "").toString();
    CompanyPreviewData.logoPATH = companyDefault.value("logo", "").toString();
    companyDefault.endGroup();

    // Preview
    companyDefault.beginGroup("preview_info");
    CompanyPreviewData.compTicker  = companyDefault.value("ticker", "").toString();
    CompanyPreviewData.compISIN    = companyDefault.value("isin", "").toString();
    CompanyPreviewData.compYear    = companyDefault.value("year", "").toString();
    CompanyPreviewData.compCountry = companyDefault.value("country", "").toString();
    CompanyPreviewData.compAddr    = companyDefault.value("addr", "").toString();
    CompanyPreviewData.compIndustry = companyDefault.value("industry", "").toString();
    CompanyPreviewData.compProperty = companyDefault.value("property", "").toString();
    CompanyPreviewData.compDivPol = companyDefault.value("divPol", "").toString();
    CompanyPreviewData.compPref = companyDefault.value("pref", "").toString();
    CompanyPreviewData.compIMOEX = companyDefault.value("imoex", "").toString();
    companyDefault.endGroup();

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

    QPair<QString,QString> p( "Clinton", "Bill" );
    QPair<QString,QString> m( "Clintonaa", "Billaa" );
    QLinHeaderList a;
    a.append(p);
    a.append(m);
    qDebug() << a;

    // 4. Scan .ini files
    QDir directory(dirINI);
    QStringList ini_files = directory.entryList(QStringList() << "*.ini" << "*.INI", QDir::Files);
    foreach(QString filename, ini_files) {

        //qDebug() << filename;
        QSettings companySett(dirINI + "/" + filename, QSettings::IniFormat);

        // main_info
        companySett.setIniCodec(codecINI);
        companySett.beginGroup("main_info");
        choiseCompany->addItem(companySett.value("name", "").toString());
        companySett.endGroup();
    }

    // Add
    choiseLayout->addWidget(choiseCompanyName);
    choiseLayout->addWidget(choiseCompany);

    QGroupBox *previewGroupBox = new QGroupBox(tr("Company Preview"));
    previewComArea = new CompanyPreviewArea(previewGroupBox, &CompanyPreviewData);
    QVBoxLayout *previewLayout = new QVBoxLayout(previewGroupBox);
    previewGroupBox->setMinimumSize(350,620);
    previewLayout->addWidget(previewComArea);

    // ==============================================
    mainTable = new CompanyTableArea;
    QTableView *tableView = new QTableView;
    tableView->setModel(mainTable);
    tableView->setMinimumWidth(800);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter | Qt::AlignTop);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter | Qt::AlignTop);

    tableView->setStyleSheet("QHeaderView::section { background-color: #FFFFDA; color: darkBlue; }");
    //tableView->verticalHeader()->setStyleSheet("QHeaderView::section { font-weight: bold; }");
    //QString s = QString("border: 1px solid %1;").arg(QColor(255,8,8).name());
    //tableView->setStyleSheet(s);
    mainTable->setParent(tableView);

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

    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QSettings settings(":/companies_datas/companies/BANE.ini", QSettings::IniFormat);
    settings.setIniCodec(codec);
    QHash<QString,QString>values;

    settings.beginGroup("main_info");
    QStringList childKeys = settings.childKeys();
    foreach (const QString &childKey,childKeys)
    values.insert(childKey, settings.value(childKey).toString());
    settings.endGroup();

    settings.beginGroup("preview_info");
    childKeys = settings.childKeys();
    foreach (const QString &childKey,childKeys)
    values.insert(childKey, settings.value(childKey).toString());
    settings.endGroup();

    qDebug() << values.value("addr").toStdString().c_str();
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
