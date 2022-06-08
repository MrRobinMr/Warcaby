#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->p = new Plansza(8);
    this->lista.append(this->ui->widget);
    this->lista.at(0)->setStyleSheet(QString("background-image: url(:/new/pionki/biale.png);"));
    qDebug()<<this->lista[0]->styleSheet();
}
MainWindow::~MainWindow()
{
    delete this->p;
    this->lista.remove(0,this->lista.length());
    delete ui;

}
void MainWindow::narysujPionki(){

    for(int i=1;i<8+1;i++){
        for(int j=1;j<8+1;j++){
            if(this->p->tab[8*i+j].getPion()=='b'){
                continue;
                //this->tabb[8*i+j-1]->setStyleSheet(QString("background-image: url(:/new/pionki/biale.png);"));
                //this->tabb[8*i+j-1]->setCursor(Qt::CursorShape::PointingHandCursor);
            }else if(this->p->tab[8*i+j].getPion()=='b'){
                continue;
                //this->tabb[8*i+j-1]->setStyleSheet(QString("background-image: url(:/new/pionki/czarne.png);"));
                //this->tabb[8*i+j-1]->setCursor(Qt::CursorShape::PointingHandCursor);
            }else{
                continue;
            }
        }
    }
}

