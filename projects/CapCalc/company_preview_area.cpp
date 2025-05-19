#include <QtWidgets>
#include "company_preview_area.h"

CompanyPreviewArea::CompanyPreviewArea(QWidget *parent, CompanyPreviewAreaInfo *data)
    : QWidget(parent) {

    QGridLayout *mainLayout = new QGridLayout(this);

    // Logo ==============================================================================
    QString logoCompany = data->logoPATH;
    QPixmap pixmap = QPixmap(logoCompany);
    QLabel *ico = new QLabel(this);
    ico->setAlignment(Qt::AlignmentFlag::AlignHCenter);
    ico->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Name ==============================================================================
    QLabel *name = new QLabel(tr("<b>%1</b>").arg(data->nameCompany));
    name->setAlignment(Qt::AlignmentFlag::AlignHCenter);

    /*QLabel *name = new QLabel(this);
    name->setAlignment(Qt::AlignmentFlag::AlignHCenter);
    name->setText(nameCompany);*/

    // Table =============================================================================
    int row = 10;
    int col = 2;
    QTextEdit *tableInfoCompany = new QTextEdit;
    tableInfoCompany->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    QTextCursor cursor(tableInfoCompany->textCursor());
    QTextTable *table = cursor.insertTable(row, col);
    QTextTableFormat tableFormat = table->format();
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));
    tableFormat.setAlignment(Qt::AlignCenter);
    tableFormat.setBorderStyle(QTextTableFormat::BorderStyle_Solid);
    tableFormat.setBorderBrush(Qt::black);
    tableFormat.setCellPadding(0);
    tableFormat.setCellSpacing(0);

    //Set the columnWidthConstraints constraints of the table
    /*QVector<QTextLength> colLength = tableFormat.columnWidthConstraints();
    for (int i = 0; i < col; ++i) {
        colLength.append(QTextLength(QTextLength::FixedLength,tableFormat.width().rawValue()/col));
    }
    tableFormat.setColumnWidthConstraints(colLength);*/

    insertAlignedText(table, 0, 0, Qt::AlignCenter, "aaa");
    insertAlignedText(table, 0, 1, Qt::AlignCenter, "bbb");

    table->setFormat(tableFormat);

    mainLayout->addWidget(ico);
    mainLayout->addWidget(name);
    mainLayout->addWidget(tableInfoCompany);
}

// Insert text with specified alignment in specified cell
void CompanyPreviewArea::insertAlignedText(QTextTable *table, int row, int col, Qt::Alignment alignment, QString text)
{
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
