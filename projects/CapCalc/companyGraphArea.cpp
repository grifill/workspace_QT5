/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Gregory Filatov
 * All rights reserved.
 *
 * \file   companyGraphArea.cpp
 * \author Gregory Filatov
 * \date   03 June 2026
 * \version 1.1
 *
 * \brief  Contains company graph area data
 *
 * Module: companyGraphArea
 *
 * Purpose: MyClass - file
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */
#include <QtWidgets>
#include "companyGraphArea.h"

/*
// ... inside a class
QVector<double> myChartData = {10.0, 20.0, 15.0};
QBarSet* barSet = new QBarSet("My Data");
// You can populate the bar set from your data vector
for (double value : myChartData) {
    barSet->append(value);
}

// Now, let's say you want to change a value
myChartData[1] = 25.0; // Change the value in your data source

// To update the chart, you need to clear the old data and add the new data.
// Note: This is a simplified example. For larger datasets,
// you might want a more efficient update mechanism.
barSet->remove(0, barSet->count());
for (double value : myChartData) {
    barSet->append(value);
}
*/

/*
// 1. Создаем набор данных (BarSet) и серию
QBarSet *set = new QBarSet("Данные");
QBarSeries *series = new QBarSeries();

// 2. Создаем или передаем существующий QVector
QVector<qreal> dataVector = {1.5, 2.3, 4.1, 3.8};

// 3. Добавляем QVector в QBarSet, конвертируя его в QList
// (требуется для совместимости в версиях Qt 5)
set->append(dataVector.toList());

// Или для современного синтаксиса в Qt 6 напрямую:
// set->append(dataVector);

// 4. Добавляем QBarSet в QBarSeries
series->append(set);
*/

CompanyGraphArea::CompanyGraphArea(QChart *chart, CompanyGraphAreaInfo *data)
    : QChart(chart) {

    QBarSet *setHigh = new QBarSet("Выручка");
    //setHigh->append(data->paramVal.toList());
    //QBarSeries *series = new QBarSeries();

    QBarSeries *series = new QBarSeries();
    QVector<qreal> dataVector = {1.5, 2.3, 4.1, 3.8};
    setHigh->append(dataVector.toList());


    /*
    for (uint32_t value : qAsConst(data->paramVal)) {
        setHigh->append(value);
    }
    series->append(set);*/


    chart->setAnimationOptions(QChart::AllAnimations);
    chart->addSeries(series);

    // Axis X -----------------------------------------
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    //axisX->append(data->years.value(0));
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Axis Y -----------------------------------------
    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}

/*
m_model = new CustomTableModel;
//! [1]

//! [2]
// create table view and add model to it
QTableView *tableView = new QTableView;
tableView->setModel(m_model);
tableView->setMinimumWidth(300);
tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
m_model->setParent(tableView);
//! [2]

//! [3]
QChart *chart = new QChart;
chart->setAnimationOptions(QChart::AllAnimations);
//! [3]

// series 1
//! [4]
QBarSeries *series = new QBarSeries;

int first = 3;
int count = 5;
QVBarModelMapper *mapper = new QVBarModelMapper(this);
mapper->setFirstBarSetColumn(1);
mapper->setLastBarSetColumn(4);
mapper->setFirstRow(first);
mapper->setRowCount(count);
mapper->setSeries(series);
mapper->setModel(m_model);
chart->addSeries(series);
//! [4]

//! [5]
// for storing color hex from the series
QString seriesColorHex = "#000000";

// get the color of the series and use it for showing the mapped area
QList<QBarSet *> barsets = series->barSets();
for (int i = 0; i < barsets.count(); i++) {
    seriesColorHex = "#" + QString::number(barsets.at(i)->brush().color().rgb(), 16).right(6).toUpper();
    m_model->addMapping(seriesColorHex, QRect(1 + i, first, 1, barsets.at(i)->count()));
}
//! [5]

//! [6]
QStringList categories;
categories << "April" << "May" << "June" << "July" << "August";
QBarCategoryAxis *axisX = new QBarCategoryAxis();
axisX->append(categories);
chart->addAxis(axisX, Qt::AlignBottom);
series->attachAxis(axisX);
QValueAxis *axisY = new QValueAxis();
chart->addAxis(axisY, Qt::AlignLeft);
series->attachAxis(axisY);
//! [6]

//! [7]
QChartView *chartView = new QChartView(chart);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(640, 480);
//! [7]

//! [8]
// create main layout
QGridLayout *mainLayout = new QGridLayout;
mainLayout->addWidget(tableView, 1, 0);
mainLayout->addWidget(chartView, 1, 1);
mainLayout->setColumnStretch(1, 1);
mainLayout->setColumnStretch(0, 0);
setLayout(mainLayout);
*/
