/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2025 Gregory Filatov
 * All rights reserved.
 *
 * \file   companyPreviewArea.cpp
 * \author Gregory Filatov
 * \date   29 September 2025
 * \version 1.1
 *
 * \brief  Contains company preview area data
 *
 * Module: companyPreviewArea
 *
 * Purpose: MyClass - file
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */
#include <QtWidgets>
#include "companyPreviewArea.h"

CompanyPreviewArea::CompanyPreviewArea(QWidget *parent, CompanyPreviewAreaInfo *data)
    : QWidget(parent) {

    companyPreviewAreaLayout = new QGridLayout(this);

    // Logo ==============================================================================
    icoCompany = createIcoLabel(data->logoPATH);

    // Name ==============================================================================
    nameCompany = createNameLabel(data->nameCompany);

    // Table =============================================================================
    tableInfoCompany = createTableLabel(*data);

    companyPreviewAreaLayout->addWidget(icoCompany);
    companyPreviewAreaLayout->addWidget(nameCompany);
    companyPreviewAreaLayout->addWidget(tableInfoCompany);
}

// Insert text with specified alignment in specified cell
void CompanyPreviewArea::insertAlignedText(QTextTable *table, int row, int col, Qt::Alignment alignment, QString text) {
    // Obtain cursor and current block format
    QTextCursor textCursor = table->cellAt(row,col).firstCursorPosition();
    QTextBlockFormat blockFormat = textCursor.blockFormat();

    // Read vertical part of current alignment flags
    Qt::Alignment vertAlign = blockFormat.alignment() & Qt::AlignVertical_Mask;

    // Mask out vertical part of specified alignment flags
    Qt::Alignment horzAlign = alignment & Qt::AlignHorizontal_Mask;

    // Combine current vertical and specified horizontal alignment
    Qt::Alignment combAlign = horzAlign | vertAlign;

    // Apply and write
    blockFormat.setAlignment(combAlign);
    textCursor.setBlockFormat(blockFormat);
    textCursor.insertText(text);
}

QLabel *CompanyPreviewArea::createNameLabel(const QString &text) {
    QLabel *label = new QLabel(tr("<b>%1</b>").arg(text));
    label->setAlignment(Qt::AlignmentFlag::AlignHCenter);
    label->update();
    return label;
}

QLabel *CompanyPreviewArea::newNameLabel(QLabel *name, const QString &text) {
    name->setText(tr("<b>%1</b>").arg(text));
    name->setAlignment(Qt::AlignmentFlag::AlignHCenter);
    name->update();
    return name;
}

QLabel *CompanyPreviewArea::createIcoLabel(const QString &text) {
    QLabel *ico = new QLabel();
    const QPixmap pixmap = QPixmap(text);
    ico->setAlignment(Qt::AlignmentFlag::AlignHCenter);
    ico->setPixmap(pixmap.scaled(120, 120, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ico->update();
    return ico;
}

QLabel *CompanyPreviewArea::newIcoLabel(QLabel *ico, const QString &text) {
    const QPixmap pixmap = QPixmap(text);
    ico->setAlignment(Qt::AlignmentFlag::AlignHCenter);
    ico->setPixmap(pixmap.scaled(120, 120, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ico->update();
    return ico;
}

QTextEdit *CompanyPreviewArea::createTableLabel(const CompanyPreviewAreaInfo &data) {
    int row = 10;
    int col = 2;
    tableInfoCompany = new QTextEdit;
    tableInfoCompany->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    QTextCursor cursor(tableInfoCompany->textCursor());
    QTextTable *table = cursor.insertTable(row, col);
    QTextTableFormat tableFormat = table->format();
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));
    tableFormat.setAlignment(Qt::AlignCenter);
    tableFormat.setBorderStyle(QTextTableFormat::BorderStyle_Solid);
    tableFormat.setBorderBrush(Qt::lightGray);
    tableFormat.setCellPadding(0);
    tableFormat.setCellSpacing(0);

    // Colomn Param
    insertAlignedText(table, 0, 0, Qt::AlignCenter, "Торговый код");
    insertAlignedText(table, 1, 0, Qt::AlignCenter, "ISIN");
    insertAlignedText(table, 2, 0, Qt::AlignCenter, "Год основания");
    insertAlignedText(table, 3, 0, Qt::AlignCenter, "Страна");
    insertAlignedText(table, 4, 0, Qt::AlignCenter, "Расположение");
    insertAlignedText(table, 5, 0, Qt::AlignCenter, "Отрасль");
    insertAlignedText(table, 6, 0, Qt::AlignCenter, "Вид собственности");
    insertAlignedText(table, 7, 0, Qt::AlignCenter, "Дивидендная политика");
    insertAlignedText(table, 8, 0, Qt::AlignCenter, "Привилегированные акции");
    insertAlignedText(table, 9, 0, Qt::AlignCenter, "Индекс IMOEX");

    insertAlignedText(table, 0, 1, Qt::AlignCenter, data.compTicker);
    insertAlignedText(table, 1, 1, Qt::AlignCenter, data.compISIN);
    insertAlignedText(table, 2, 1, Qt::AlignCenter, data.compYear);
    insertAlignedText(table, 3, 1, Qt::AlignCenter, data.compCountry);
    insertAlignedText(table, 4, 1, Qt::AlignCenter, data.compAddr);
    insertAlignedText(table, 5, 1, Qt::AlignCenter, data.compIndustry);
    insertAlignedText(table, 6, 1, Qt::AlignCenter, data.compProperty);
    insertAlignedText(table, 7, 1, Qt::AlignCenter, data.compDivPol);
    insertAlignedText(table, 8, 1, Qt::AlignCenter, data.compPref);
    insertAlignedText(table, 9, 1, Qt::AlignCenter, data.compIMOEX);

    table->setFormat(tableFormat);
    tableInfoCompany->update();
    return tableInfoCompany;
}

QTextEdit *CompanyPreviewArea::newTableLabel(QTextEdit *name, const CompanyPreviewAreaInfo &data) {
    int row = 10;
    int col = 2;
    name->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    QTextCursor cursor(name->textCursor());
    QTextTable *table = cursor.insertTable(row, col);
    QTextTableFormat tableFormat = table->format();
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));
    tableFormat.setAlignment(Qt::AlignCenter);
    tableFormat.setBorderStyle(QTextTableFormat::BorderStyle_Solid);
    tableFormat.setBorderBrush(Qt::lightGray);
    tableFormat.setCellPadding(0);
    tableFormat.setCellSpacing(0);

    // Colomn Param
    insertAlignedText(table, 0, 0, Qt::AlignCenter, "Торговый код");
    insertAlignedText(table, 1, 0, Qt::AlignCenter, "ISIN");
    insertAlignedText(table, 2, 0, Qt::AlignCenter, "Год основания");
    insertAlignedText(table, 3, 0, Qt::AlignCenter, "Страна");
    insertAlignedText(table, 4, 0, Qt::AlignCenter, "Расположение");
    insertAlignedText(table, 5, 0, Qt::AlignCenter, "Отрасль");
    insertAlignedText(table, 6, 0, Qt::AlignCenter, "Вид собственности");
    insertAlignedText(table, 7, 0, Qt::AlignCenter, "Дивидендная политика");
    insertAlignedText(table, 8, 0, Qt::AlignCenter, "Привилегированные акции");
    insertAlignedText(table, 9, 0, Qt::AlignCenter, "Индекс IMOEX");

    insertAlignedText(table, 0, 1, Qt::AlignCenter, data.compTicker);
    insertAlignedText(table, 1, 1, Qt::AlignCenter, data.compISIN);
    insertAlignedText(table, 2, 1, Qt::AlignCenter, data.compYear);
    insertAlignedText(table, 3, 1, Qt::AlignCenter, data.compCountry);
    insertAlignedText(table, 4, 1, Qt::AlignCenter, data.compAddr);
    insertAlignedText(table, 5, 1, Qt::AlignCenter, data.compIndustry);
    insertAlignedText(table, 6, 1, Qt::AlignCenter, data.compProperty);
    insertAlignedText(table, 7, 1, Qt::AlignCenter, data.compDivPol);
    insertAlignedText(table, 8, 1, Qt::AlignCenter, data.compPref);
    insertAlignedText(table, 9, 1, Qt::AlignCenter, data.compIMOEX);

    table->setFormat(tableFormat);
    name->update();
    return name;
}

void CompanyPreviewArea::infoDataChange(CompanyPreviewAreaInfo *data) {
    qDebug("infoDataChange --- >>>");

    nameCompany = newNameLabel(nameCompany, data->nameCompany);
    icoCompany = newIcoLabel(icoCompany, data->logoPATH);

    //emit infoDataChanged(data);
    repaint();
}
