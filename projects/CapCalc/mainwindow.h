#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

#include "customtable.h"
#include "company_preview_area.h"

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
    void show();

    CustomTable *model;
    CompanyPreviewArea *previewComArea;


    CompanyPreviewAreaInfo CompanyPreviewData;
private slots:
    //void screenChanged();
    void about();
    void reprint(const QString &company);
private:
    void createActions();
     //QLabel *devicePixelRatioLabel;
     //QLabel *screenNameLabel;
};

#endif // MAINWINDOW_H
