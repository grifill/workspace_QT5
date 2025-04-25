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
    std::list<std::pair<Date, int>> mapCUR;

    QStringList dates;
    mapVL=autoDictFill(mapVL, START_MONTH, START_YEAR, MONTH_CNT, (int*)vlMass);
    mapCUR=autoDictFill(mapCUR, START_MONTH, START_YEAR, MONTH_CNT, (int*)curMass);

    QBarSeries *series = new QBarSeries;

    QChart *chart = new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);

    QBarSet *paramVL = new QBarSet("My Map VL");
    QBarSet *paramCUR = new QBarSet("My Map CUR");

    IGNORE_MEMORY_LEAK_WARNING(paramVL);
    IGNORE_MEMORY_LEAK_WARNING(paramCUR);

    for(auto itVL=mapVL.begin(), itCUR=mapCUR.begin();
        (itVL!=mapVL.end())&&(itCUR!=mapCUR.end());
        ++itVL, ++itCUR) {

        dates << itVL->first.toString().c_str();
        *paramVL << itVL->second;
        *paramCUR << itCUR->second;

        series->append(paramVL);
        series->append(paramCUR);

        //std::cout << itCUR->first << ": " << itCUR->second << "\n";
     }

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
