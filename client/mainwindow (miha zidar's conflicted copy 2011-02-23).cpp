#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QPainter>
#include <cstdlib>

static int graphData[DATA_LENGTH];
static int sleepInterval = 1;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::DataReceived(QString text){
    ui->textEdit->setPlainText(text+ui->textEdit->toPlainText());
}

void MainWindow::ConnectError(){
    QMessageBox::warning(this, "Napaka", "Napaka v povezavi.");
}


void MainWindow::on_getTempAllButton_clicked(){
    //ui->textEdit->clear();
    Client *client = new Client(ui->lineEditAddr->text(), ui->lineEditPort->text(), "" ,"get_temp_all", "" );
    connect(client, SIGNAL(dataReceived(QString)), this, SLOT(DataReceived(QString)));
    connect(client, SIGNAL(connectError()), this, SLOT(ConnectError()));
    client->start();
}

void MainWindow::on_getTempButton_clicked(){
    //ui->textEdit->clear();
    //Client *client = new Client(ui->lineEditAddr->text(), ui->lineEditPort->text(), "" ,"get_single_temp", "" );
    //connect(client, SIGNAL(dataReceived(QString)), this, SLOT(DataReceived(QString)));
    //connect(client, SIGNAL(connectError()), this, SLOT(ConnectError()));
    //client->start();
    int threadStatus;

    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //todo: nared da dela !!!!!!!!!
   // if ((threadStatus = pthread_create(&thread,&attr, refreshData, NULL))){
        QMessageBox::warning(this, "Napaka", "O yoyy neki ne dela, nitke so se strgale.");
    //}else{

    //}

}

void MainWindow::on_getLastTempButton_clicked(){
    //ui->textEdit->clear();
    Client *client = new Client(ui->lineEditAddr->text(), ui->lineEditPort->text(), "" ,"get_last_temp", "" );
    connect(client, SIGNAL(dataReceived(QString)), this, SLOT(DataReceived(QString)));
    connect(client, SIGNAL(connectError()), this, SLOT(ConnectError()));
    client->start();
}

void MainWindow::paintEvent(QPaintEvent*){
  QPainter p(this);
  QPainterPath pp;
  int i;
  int x = ui->widget_5->x()+ui->widget_4->x()+ui->widget_2->x();
  int y = ui->widget_5->y()+ui->widget_4->y()+ui->widget_2->y()+15;
  int width = ui->widget_5->width();
  int height = ui->widget_5->height();
  //TODO: narisati graf  iz vhodnih podatkov v zanki.
  p.setRenderHint(QPainter::Antialiasing,true);
  p.drawLine(x,y,x+width,y);
  p.drawLine(x,y+height,x+width,y+height);
  p.drawLine(x,y,x,y+height);
  p.drawLine(x+width,y,x+width,y+height);

  //for (i=0 ; i < DATA_LENGTH ; i++){ graphData[i] = std::rand() % height; }

  pp.moveTo(x,y+height-graphData[0]);
  for (i=1 ; i < DATA_LENGTH ; i++){
      pp.lineTo(x+(width/(DATA_LENGTH-1))*i,y+height-graphData[i]);
  }
  p.drawPath(pp);
}

void MainWindow::on_clearButton_clicked(){
    ui->textEdit->clear();
}

void MainWindow::refreshData(){
  for (;;){
    usleep(sleepInterval*1000000);
    int i;
    for (i=0 ; i < DATA_LENGTH ; i++){ graphData[i] = std::rand() % 100; }
    this->update();
  }
}
