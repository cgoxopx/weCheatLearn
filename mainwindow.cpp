#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->web->load(QUrl("https://course.sflep.com"));

    goNextTimer = new QTimer(this);
    connect(goNextTimer, &QTimer::timeout, this, &MainWindow::goNextHandle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goNext()
{
    ui->web->page()->runJavaScript("NextSCO();");
}

void MainWindow::goPre()
{
    ui->web->page()->runJavaScript("PrevSCO();");
}

void MainWindow::on_pushButton_goPre_clicked()
{
    goPre();
}

void MainWindow::on_pushButton_goNext_clicked()
{
    goNext();
}

void MainWindow::goNextHandle()
{
    goNext();
}

void MainWindow::on_pushButton_goNext_stop_clicked()
{
    goNextTimer->stop();
}

void MainWindow::on_pushButton_goNext_start_clicked()
{
    goNextTimer->start(ui->spinBox_goNext_tm->value()*1000);
}
