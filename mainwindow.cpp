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
/*void MainWindow::narysujPionki(){
    for(int i=1;i<8+1;i++){
        for(int j=1;j<8+1;j++){

        }
    }
}*/

