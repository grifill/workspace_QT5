#ifndef COMPANY_PREVIEW_AREA_H
#define COMPANY_PREVIEW_AREA_H

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
    QString nameCompany;
    QString logoPATH;
};

//! [0]
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

#endif // COMPANY_PREVIEW_AREA_H
