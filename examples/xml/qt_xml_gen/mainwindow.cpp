#include "mainwindow.h"
#include "ui_mainwindow.h"

extern void DictF();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    DictF();
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

