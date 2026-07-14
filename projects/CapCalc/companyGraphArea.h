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

#include <QList>
#include <QBarSet>
#include <QFile>

#include <QtCharts>
#include <QChartView>


struct CompanyGraphAreaInfo
{
    // Description
    QString paramName;
    QStringList years;
    QVector<uint32_t> paramVals;
};

class CompanyGraphArea : public QChart
{
    Q_OBJECT

public:
    explicit CompanyGraphArea(QtCharts::QChart *chart = nullptr, CompanyGraphAreaInfo *data = nullptr);
    //virtual ~CompanyGraphArea();

private:
    // Graph
    //QChart *graphCompany;
};

#endif // COMPANYGRAPHAREA_H

