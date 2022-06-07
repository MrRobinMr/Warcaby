#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->p = new Plansza(8);
    //this->narysujPionki();
    //std::cout<<typeid(ui->p1).name();

}
MainWindow::~MainWindow()
{
    delete this->p;
    delete ui;
}
void MainWindow::narysujPionki(){
    for(int i=1;i<8+1;i++){
        for(int j=1;j<8+1;j++){
            if(this->p->tab[8*i+j].getPion()=='b'){
                continue;
//#define temp 8*i+j;
                //this->ui->("p"+"1")->setStyleSheet("background-image: url(:/new/pionki/biale.png);");
            }
        }
    }
}

