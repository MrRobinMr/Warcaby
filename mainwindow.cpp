#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    p = new Plansza(8);
}
MainWindow::~MainWindow()
{
    p->wyczysc();
    delete p;
    delete ui;
}

