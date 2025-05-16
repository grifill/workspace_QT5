#include <QtWidgets>
#include "company_preview_area.h"

CompanyPreviewArea::CompanyPreviewArea(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *mainLayout = new QGridLayout(this);

    for (int row = 0; row < NumStates; ++row) {
        stateLabels[row] = createHeaderLabel(CompanyPreviewArea::iconStateNames().at(row));
        mainLayout->addWidget(stateLabels[row], row + 1, 0);
    }
    Q_ASSERT(NumStates == 2);

    for (int column = 0; column < NumModes; ++column) {
        modeLabels[column] = createHeaderLabel(CompanyPreviewArea::iconModeNames().at(column));
        mainLayout->addWidget(modeLabels[column], 0, column + 1);
    }
    Q_ASSERT(NumModes == 4);

    for (int column = 0; column < NumModes; ++column) {
        for (int row = 0; row < NumStates; ++row) {
            pixmapLabels[column][row] = createPixmapLabel();
            mainLayout->addWidget(pixmapLabels[column][row], row + 1, column + 1);
        }
    }
}


QVector<QIcon::Mode> CompanyPreviewArea::iconModes()
{
    static const QVector<QIcon::Mode> result = {QIcon::Normal, QIcon::Active, QIcon::Disabled, QIcon::Selected};
    return result;
}

QVector<QIcon::State> CompanyPreviewArea::iconStates()
{
    static const QVector<QIcon::State> result = {QIcon::Off, QIcon::On};
    return result;
}

QStringList CompanyPreviewArea::iconModeNames()
{
    static const QStringList result = {tr("Normal"), tr("Active"), tr("Disabled"), tr("Selected")};
    return result;
}

QStringList CompanyPreviewArea::iconStateNames()
{
    static const QStringList result = {tr("Off"), tr("On")};
    return result;
}


void CompanyPreviewArea::setIcon(const QIcon &icon)
{
    this->icon = icon;
    updatePixmapLabels();
}


void CompanyPreviewArea::setSize(const QSize &size)
{
    if (size != this->size) {
        this->size = size;
        updatePixmapLabels();
    }
}


QLabel *CompanyPreviewArea::createHeaderLabel(const QString &text)
{
    QLabel *label = new QLabel(tr("<b>%1</b>").arg(text));
    label->setAlignment(Qt::AlignCenter);
    return label;
}


QLabel *CompanyPreviewArea::createPixmapLabel()
{
    QLabel *label = new QLabel;
    label->setEnabled(false);
    label->setAlignment(Qt::AlignCenter);
    label->setFrameShape(QFrame::Box);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setBackgroundRole(QPalette::Base);
    label->setAutoFillBackground(true);
    label->setMinimumSize(132, 132);
    return label;
}


void CompanyPreviewArea::updatePixmapLabels()
{
    QWindow *window = nullptr;
    if (const QWidget *nativeParent = nativeParentWidget())
        window = nativeParent->windowHandle();
    for (int column = 0; column < NumModes; ++column) {
        for (int row = 0; row < NumStates; ++row) {
            const QPixmap pixmap =
                icon.pixmap(window, size, CompanyPreviewArea::iconModes().at(column),
                            CompanyPreviewArea::iconStates().at(row));
            QLabel *pixmapLabel = pixmapLabels[column][row];
            pixmapLabel->setPixmap(pixmap);
            pixmapLabel->setEnabled(!pixmap.isNull());
            QString toolTip;
            if (!pixmap.isNull()) {
                const QSize actualSize = icon.actualSize(size);
                toolTip =
                    tr("Size: %1x%2\nActual size: %3x%4\nDevice pixel ratio: %5")
                        .arg(size.width()).arg(size.height())
                        .arg(actualSize.width()).arg(actualSize.height())
                        .arg(pixmap.devicePixelRatioF());
            }
            pixmapLabel->setToolTip(toolTip);
        }
    }
}
