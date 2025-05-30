/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2025 Gregory Filatov
 * All rights reserved.
 *
 * \file   companyPreviewArea.h
 * \author Gregory Filatov
 * \date   30 May 2025
 * \version 1.0
 *
 * \brief  Contains company preview area data
 *
 * Module: companyPreviewArea.h
 *
 * Purpose: MyClass - file
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */
#ifndef COMPANYPREVIEWAREA_H
#define COMPANYPREVIEWAREA_H

#include <QIcon>
#include <QWidget>
#include <QStringList>
#include <QVector>
#include <QTextTable>
#include <QTextEdit>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

struct CompanyPreviewAreaInfo
{
    // Description
    QString nameCompany;
    QString logoPATH;

    // Table
    QString compTicker;
    QString compISIN;
    QString compYear;
    QString compCountry;
    QString compAddr;
    QString compIndustry;
    QString compProperty;
    QString compDivPol;
    QString compPref;
    QString compIMOEX;
};

class CompanyPreviewArea : public QWidget
{
    Q_OBJECT

public:
    explicit CompanyPreviewArea(QWidget *parent = nullptr, CompanyPreviewAreaInfo *data = nullptr);
    void infoDataChange(CompanyPreviewAreaInfo *data);
signals:
    void infoDataChanged(CompanyPreviewAreaInfo *data);

private:
    void insertAlignedText(QTextTable *table, int row, int col, Qt::Alignment alignment, QString text);
    QLabel *createNameLabel(const QString &text);
    QLabel *createIcoLabel(const QString &text);
    QLabel *newNameLabel(QLabel *name, const QString &text);
    QLabel *newIcoLabel(QLabel *ico, const QString &text);

    QString logoCompany;
    QLabel *nameCompany;
    QLabel *icoCompany;
    QTextEdit *tableInfoCompany;
    QGridLayout *companyPreviewAreaLayout;
};

#endif // COMPANYPREVIEWAREA_H
