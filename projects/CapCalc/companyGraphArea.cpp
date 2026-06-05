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


CompanyGraphArea::CompanyGraphArea(QWidget *parent, CompanyGraphAreaInfo *data)
    : QWidget(parent) {

    graphCompany = createGraphLabel();

}

QChartView *CompanyGraphArea::createGraphLabel() {

    QChart *chart = new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);


    //chart->addSeries(series);

    // Axis X -----------------------------------------
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    //axisX->append(dates);
    chart->addAxis(axisX, Qt::AlignBottom);
    //series->attachAxis(axisX);

    // Axis Y -----------------------------------------
    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    //series->attachAxis(axisY);


    //QChartView *chartView = new QChartView(chart);

    // QChartView Window ------------------------------
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(320, 240);
    return chartView;
}
