#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    xmlWriter.writeStartElement("description");

    xmlWriter.writeStartElement("Company");  // Записываем тег с именем для первого чекбокса
    xmlWriter.writeCharacters("AFKS");
    xmlWriter.writeEndElement();             // Закрываем тег

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();   // Закрываем файл
}

