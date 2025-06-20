/**
 * ---------------------------------------------------------------------------
 * Copyright (c) 2025 Gregory Filatov
 * All rights reserved.
 *
 * \file   mainwindow.h
 * \author Gregory Filatov
 * \date   30 May 2025
 * \version 1.0
 *
 * \brief  Contains main - mainwindow
 *
 * Module: mainwindow.h
 *
 * Purpose: Mainwindow - file
 *
 * Functionality:
 *     Environment
 * ---------------------------------------------------------------------------
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QTableView>
#include <QHeaderView>
#include <QList>
#include <QWindow>
#include <QScreen>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QGroupBox>
#include <QComboBox>
#include <QFrame>
#include <QLineEdit>
#include <QSettings>
#include <QDebug>
#include <QtCore>
#include <QTextCodec>

#include "companyTableArea.h"
#include "companyPreviewArea.h"

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QRadioButton;
class QButtonGroup;
class QTableWidget;
QT_END_NAMESPACE
class IconPreviewArea;
class IconSizeSpinBox;

//! [0]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    void show();

    CompanyTableArea *mainTable;
    CompanyPreviewArea *previewComArea;
    CompanyPreviewAreaInfo CompanyPreviewData;

    QWidget *placeholderWidget;
    QGridLayout *mainLayout;

public slots:
    void reprint(const QString &company);
private slots:
    //void screenChanged();
    void about();
private:
    void createActions();
     //QLabel *devicePixelRatioLabel;
     //QLabel *screenNameLabel;
};

#endif // MAINWINDOW_H
