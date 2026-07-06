/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Gregory Filatov
 * All rights reserved.
 *
 * \file   companyGraphArea.h
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
#ifndef COMPANYGRAPHAREA_H
#define COMPANYGRAPHAREA_H


#include <QWidget>
#include <QStringList>
#include <QVector>
#include <QString>

#include <QChartView>
#include <QList>
#include <QBarSet>
#include <QFile>
#include <QtCharts>


struct CompanyGraphAreaInfo
{
    // Description
    uint32_t datas;
    uint32_t dates;
};

class CompanyGraphArea : public QChart
{
    Q_OBJECT

public:
    explicit CompanyGraphArea(QGraphicsItem *parent = nullptr, CompanyGraphAreaInfo *data = nullptr);

private:
    QChart *createGraphLabel(QChart *chart);

    // Graph
    QChart *graphCompany;
};

#endif // COMPANYGRAPHAREA_H

