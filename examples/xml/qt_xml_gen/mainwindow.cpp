#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "MyDict/dict_IIS.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked() {

    // Вызываем диалог выбора файла для сохранения
    QString filename = QFileDialog::getSaveFileName(this,
                                           tr("Save Xml"), ".",
                                           tr("Xml files (*.xml)"));
    if(filename != ""){
        ui->lineEditWrite->setText(filename);
    }

    // Открываем файл для Записи с помощью пути, указанного в lineEditWrite
    QFile file(ui->lineEditWrite->text());
    file.open(QIODevice::WriteOnly);

    // Создаем объект, с помощью которого осуществляется запись в файл
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("MyBalance"); // Start 1
    xmlWriter.writeStartElement("Earnings");   // Start 2
    xmlWriter.writeStartElement("NetSpend");  // Start 3
    xmlWriter.writeStartElement("Zarpalata");  // Start 4

    xmlWriter.writeCharacters("10.04.2025 - 250000 Rub");   // CH

    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();

    xmlWriter.writeEndDocument();
    file.close();   // Закрываем файл
}


extern void FuncFF();
#include "MyClasses/myClassesData.h"
#include "MyDict/dict_IIS.h"
#include <stdint.h>
#include <iostream>
#include <list>
#include <string>
#include <stdio.h>
#include <utility>
#include <map>

#include "MyClasses/myClassesData.h"
#include "MyDict/dict_IIS.h"

#include <QString>
#include <QList>
#include <QBarSet>
#include <QStandardItemModel>

#include <cstdio>
#include <format>
#include <initializer_list>
#include <iostream>
#include <string>

auto autoDictFill(std::list<std::pair<Date, int>>& mapFill, int monthStart, int yearStart, int monthCnt, int* massData) {
    for(int i = 0; i < monthCnt; ++i) {
        mapFill.emplace(mapFill.end(), Date(DEFAULT_DAY, monthStart, yearStart), massData[i]);
        monthStart++;
        if(!(monthStart % 13)) {
            yearStart++;
            monthStart = 1;
        }
    }
     return mapFill;
}

void MainWindow::on_pushButton_clicked() {

    std::list<std::pair<Date, int>> mapVL;
    QStringList dates;
    mapVL=autoDictFill(mapVL, START_MONTH, START_YEAR, 32, (int*)vlMass);

    QBarSeries *series = new QBarSeries;

    QChart *chart = new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);

    QBarSet *param = new QBarSet("My Map VL");

    for(auto it = mapVL.begin(); it != mapVL.end(); ++it) {
          dates << it->first.toString().c_str();
          //QBarSet *param = new QBarSet(it->first.toString().c_str());
          *param << it->second;
          series->append(param);
          std::cout << it->first << ": " << it->second << "\n";
    }

    //int first = 3;
    //int count = 5;
    //QVBarModelMapper *mapper = new QVBarModelMapper(this);
    //mapper->setFirstBarSetColumn(1);
    //mapper->setLastBarSetColumn(4);
    //mapper->setFirstRow(first);
    //mapper->setRowCount(count);
    //mapper->setSeries(series);
    //mapper->setModel(m_model);
    //chart->addSeries(series);

    chart->addSeries(series);

    // Axis X -----------------------------------------
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(dates);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Axis Y -----------------------------------------
    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // QChartView Window ------------------------------
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(640, 480);

    // Create main layout -----------------------------
    QWidget *placeholderWidget = new QWidget;
    QGridLayout *sainLayout = new QGridLayout;
    sainLayout->addWidget(chartView, 1, 1);
    sainLayout->setColumnStretch(1, 1);
    sainLayout->setColumnStretch(0, 0);
    placeholderWidget->setLayout(sainLayout);
    setCentralWidget(placeholderWidget);
}

