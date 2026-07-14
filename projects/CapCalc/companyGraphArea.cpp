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

CompanyGraphArea::CompanyGraphArea(QChart *chart, CompanyGraphAreaInfo *data)
    : QChart(chart) {

    QBarSet *setHigh = new QBarSet(data->paramName);
    QBarSeries *series = new QBarSeries();

    setHigh->append(data->paramVals.toList());

    chart->setAnimationOptions(QChart::AllAnimations);
    chart->addSeries(series);

    // Axis X -----------------------------------------
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(data->years);
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
