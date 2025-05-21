#ifndef COMPANY_PREVIEW_AREA_H
#define COMPANY_PREVIEW_AREA_H

#include <QIcon>
#include <QWidget>
#include <QStringList>
#include <QVector>
#include <QTextTable>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

struct CompanyPreviewAreaInfo
{
    QString nameCompany;
    QString logoPATH;
};

//! [0]
class CompanyPreviewArea : public QWidget
{
    Q_OBJECT

public:
    explicit CompanyPreviewArea(QWidget *parent = nullptr, CompanyPreviewAreaInfo *data = nullptr);
    void infoDataChange(CompanyPreviewAreaInfo *newData);
private:
    void insertAlignedText(QTextTable *table, int row, int col, Qt::Alignment alignment, QString text);
signals:
    void companyPreviewAreaInfoDataChanged(CompanyPreviewAreaInfo *data);
};

#endif // COMPANY_PREVIEW_AREA_H
