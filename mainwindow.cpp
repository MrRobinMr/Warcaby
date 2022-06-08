#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->p = new Plansza(8);
    this->tabb.append({this->ui->p1,this->ui->p2,this->ui->p3,this->ui->p4,this->ui->p5,this->ui->p6,this->ui->p7,this->ui->p8,this->ui->p9,this->ui->p10,this->ui->p11,this->ui->p12,this->ui->p13,this->ui->p14,this->ui->p15,this->ui->p16,this->ui->p17,this->ui->p18,this->ui->p19,this->ui->p20,this->ui->p21,this->ui->p22,this->ui->p23,this->ui->p24,this->ui->p25,this->ui->p26,this->ui->p27,this->ui->p28,this->ui->p29,this->ui->p30,this->ui->p31,this->ui->p32,this->ui->p33,this->ui->p34,this->ui->p35,this->ui->p36,this->ui->p37,this->ui->p38,this->ui->p39,this->ui->p40,this->ui->p41,this->ui->p42,this->ui->p43,this->ui->p44,this->ui->p45,this->ui->p46,this->ui->p47,this->ui->p48,this->ui->p49,this->ui->p50,this->ui->p51,this->ui->p52,this->ui->p53,this->ui->p54,this->ui->p55,this->ui->p56,this->ui->p57,this->ui->p58,this->ui->p59,this->ui->p60,this->ui->p61,this->ui->p62,this->ui->p63,this->ui->p64});
    this->narysujPionki();
    qDebug()<<this->tabb[0]->objectName();
}
MainWindow::~MainWindow()
{
    delete this->p;
    this->tabb.remove(0,this->tabb.length());
    delete ui;

}
void MainWindow::narysujPionki(){

    for(int i=1;i<8+1;i++){
        for(int j=1;j<8+1;j++){
            if(this->p->tab[8*i+j].getPion()=='b'){
                this->tabb[8*i+j-1]->setStyleSheet(QString("background-image: url(:/new/pionki/biale.png);"));
                this->tabb[8*i+j-1]->setCursor(Qt::CursorShape::PointingHandCursor);
            }else if(this->p->tab[8*i+j].getPion()=='b'){
                this->tabb[8*i+j-1]->setStyleSheet(QString("background-image: url(:/new/pionki/czarne.png);"));
                this->tabb[8*i+j-1]->setCursor(Qt::CursorShape::PointingHandCursor);
            }else{
                continue;
            }
        }
    }
}

