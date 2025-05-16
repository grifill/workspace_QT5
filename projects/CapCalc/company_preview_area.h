#ifndef COMPANY_PREVIEW_AREA_H
#define COMPANY_PREVIEW_AREA_H

#include <QIcon>
#include <QWidget>
#include <QStringList>
#include <QVector>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

//! [0]
class CompanyPreviewArea : public QWidget
{
    Q_OBJECT

public:
    explicit CompanyPreviewArea(QWidget *parent = nullptr);

    void setIcon(const QIcon &icon);
    void setSize(const QSize &size);

    static QVector<QIcon::Mode> iconModes();
    static QVector<QIcon::State> iconStates();
    static QStringList iconModeNames();
    static QStringList iconStateNames();

private:
    QLabel *createHeaderLabel(const QString &text);
    QLabel *createPixmapLabel();
    void updatePixmapLabels();

    enum { NumModes = 4, NumStates = 2 };

    QIcon icon;
    QSize size;
    QLabel *stateLabels[NumStates];
    QLabel *modeLabels[NumModes];
    QLabel *pixmapLabels[NumModes][NumStates];
};

#endif // COMPANY_PREVIEW_AREA_H
