#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "MyDict/dict_IIS.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked() {

    // Вызываем диалог выбора файла для сохранения
    QString filename = QFileDialog::getSaveFileName(this,
                                           tr("Save Xml"), ".",
                                           tr("Xml files (*.xml)"));
    if(filename != ""){
        ui->lineEditWrite->setText(filename);
    }

    // Открываем файл для Записи с помощью пути, указанного в lineEditWrite
    QFile file(ui->lineEditWrite->text());
    file.open(QIODevice::WriteOnly);

    // Создаем объект, с помощью которого осуществляется запись в файл
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("MyBalance"); // Start 1
    xmlWriter.writeStartElement("Earnings");   // Start 2
    xmlWriter.writeStartElement("NetSpend");  // Start 3
    xmlWriter.writeStartElement("Zarpalata");  // Start 4

    xmlWriter.writeCharacters("10.04.2025 - 250000 Rub");   // CH

    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();

    xmlWriter.writeEndDocument();
    file.close();   // Закрываем файл
}


extern void FuncFF();
#include "MyClasses/myClassesData.h"
#include "MyDict/dict_IIS.h"

void MainWindow::on_pushButton_clicked() {

    FuncFF();

    QChart *chart = new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);
    QBarSeries *series = new QBarSeries;
    QVBarModelMapper *mapper = new QVBarModelMapper(this);
    mapper->setFirstBarSetColumn(2);
    mapper->setLastBarSetColumn(4);
    mapper->setFirstRow(3);
    mapper->setRowCount(5);
    mapper->setSeries(series);
    chart->addSeries(series);

    QStringList categories;
    categories << "April" << "May" << "June" << "July" << "August";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(640, 480);
    //! [7]

    //! [8]
    // create main layout
    QWidget *placeholderWidget = new QWidget;
    QGridLayout *sainLayout = new QGridLayout;
    sainLayout->addWidget(chartView, 1, 1);
    sainLayout->setColumnStretch(1, 1);
    sainLayout->setColumnStretch(0, 0);
    //setLayout(sainLayout);
    placeholderWidget->setLayout(sainLayout);
    setCentralWidget(placeholderWidget);

}

