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

    // 4. Scan .ini files =========================================
    QDir directory(dirINI);
    QStringList ini_files = directory.entryList(QStringList() << "*.ini" << "*.INI", QDir::Files);
    foreach(QString filename, ini_files) {

        //qDebug() << filename;
        QSettings companySett(dirINI + "/" + filename, QSettings::IniFormat);
        QString mainName;
        CompanyPreviewAreaInfo newCompPreview;

        // main_info
        companySett.setIniCodec(codecINI);
        companySett.beginGroup("main_info");

        // for combobox
        choiseCompany->addItem(companySett.value("name", "").toString());
        mainName = companySett.value("name", "").toString();

        // for main info preview
        newCompPreview.nameCompany = companySett.value("name", "").toString();
        newCompPreview.logoPATH = companySett.value("logo", "").toString();

        companySett.endGroup();

        // for preview data
        companySett.beginGroup("preview_info");
        newCompPreview.compTicker  = companySett.value("ticker", "").toString();
        newCompPreview.compISIN    = companySett.value("isin", "").toString();
        newCompPreview.compYear    = companySett.value("year", "").toString();
        newCompPreview.compCountry = companySett.value("country", "").toString();
        newCompPreview.compAddr    = companySett.value("addr", "").toString();
        newCompPreview.compIndustry = companySett.value("industry", "").toString();
        newCompPreview.compProperty = companySett.value("property", "").toString();
        newCompPreview.compDivPol = companySett.value("divPol", "").toString();
        newCompPreview.compPref = companySett.value("pref", "").toString();
        newCompPreview.compIMOEX = companySett.value("imoex", "").toString();
        companySett.endGroup();

        // Add to list
        QPair<QString,CompanyPreviewAreaInfo> newCompany(mainName, newCompPreview);
        companiesView.append(newCompany);

        // Default cfg
        if (defaultINI == filename) {
            CompanyPreviewData = newCompPreview;
        }
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

    QPair<QString, CompanyPreviewAreaInfo> pair;
    foreach (pair, companiesView) {
        if (company == pair.first) {

            // Change Data
            previewComArea->infoDataChange(&CompanyPreviewData);
            qDebug() << company;
        }
    }

    qApp->processEvents();
}
