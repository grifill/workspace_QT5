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


CompanyGraphArea::CompanyGraphArea(QGraphicsItem *parent)
    : QChart(parent) {

    QChart *chart = new QChart(this);
    graphCompany = createGraphLabel(chart);
}

QChart *CompanyGraphArea::createGraphLabel(QChart *chart) {

    QBarSet *setHigh = new QBarSet("Выручка");
    *setHigh << 340 << 410 << 450 << 500;

    QStringList dates;
    dates << "Q1" << "Q2" << "Q3" << "Q4";


    QBarSeries *series = new QBarSeries;
    series->append(setHigh);
    chart->setAnimationOptions(QChart::AllAnimations);

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

    chart->createDefaultAxes();

    return chart;
}
