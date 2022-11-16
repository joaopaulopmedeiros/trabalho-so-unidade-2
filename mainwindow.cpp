#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //instanciação dos trens (ID, posição X, posição Y)
    trem1 = new Trem(1,60,70);
    trem2 = new Trem(2,380,30);
    trem3 = new Trem(3,870,70);
    trem4 = new Trem(4,195,190);
    trem5 = new Trem(5,735,190);

    //início da movimentação dos trens
    start_trains();

    /*
     * conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * os 3 parâmetros INT do sinal serão utilizados na função.
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
}

/**
 * função que será executada quando o sinal UPDATEGUI for emitido.
 * atualiza a posição do objeto da tela (quadrado) que representa o trem
 * a depender de seu id
 */
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1:
        ui->trem1x->setText(QString::number(x));
        ui->trem1y->setText(QString::number(y));
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2:
        ui->trem2x->setText(QString::number(x));
        ui->trem2y->setText(QString::number(y));
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3:
        ui->trem3x->setText(QString::number(x));
        ui->trem3y->setText(QString::number(y));
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4:
        ui->trem4x->setText(QString::number(x));
        ui->trem4y->setText(QString::number(y));
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5:
        ui->trem5x->setText(QString::number(x));
        ui->trem5y->setText(QString::number(y));
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::calcValue(int value, int percent) {
    return value * percent;
}

QString MainWindow::getFormatedValue(int value) {
    return QString::number(value) + " ms";
}

/*
 * Ao clicar, trens começam execução
 */
void MainWindow::start_trains()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

void MainWindow::on_velTrem01_valueChanged(int value)
{
    int velocidade = this->calcValue(5, value);
    trem1->setVelocidade(velocidade);
    ui->vel01->setText(this->getFormatedValue(velocidade));
}

void MainWindow::on_velTrem02_valueChanged(int value)
{
    int velocidade = this->calcValue(5, value);
    trem2->setVelocidade(velocidade);
    ui->vel02->setText(this->getFormatedValue(velocidade));
}

void MainWindow::on_velTrem04_valueChanged(int value)
{
    int velocidade = this->calcValue(5, value);
    trem4->setVelocidade(velocidade);
    ui->vel04->setText(this->getFormatedValue(velocidade));
}

void MainWindow::on_velTrem03_valueChanged(int value)
{
    int velocidade = this->calcValue(5, value);
    trem3->setVelocidade(velocidade);
    ui->vel03->setText(this->getFormatedValue(velocidade));
}

void MainWindow::on_velTrem05_valueChanged(int value)
{
    int velocidade = this->calcValue(5, value);
    trem5->setVelocidade(velocidade);
    ui->vel05->setText(this->getFormatedValue(velocidade));
}
