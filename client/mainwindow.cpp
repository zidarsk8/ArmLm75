#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QPainter>
#include <cstdlib>
#include <qbrush.h>


static int graphData[DATA_LENGTH];
static int sleepInterval = 1;
int myTimerID = -1;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::DataReceived(QString text){
    int temp = text.toInt();
    if (myTimerID != -1){
        int bottomRange = 150;
        int topRange = 200; //razpon temperature od 15C do 35C
        int i;
        for (i=0 ; i < DATA_LENGTH-1 ; i++){
            graphData[i] = graphData[i+1];
        }
        graphData[DATA_LENGTH-1] = (int)(((float)(temp-bottomRange)/topRange)*ui->widget_5->height());
        if (graphData[DATA_LENGTH-1] < 0 ){
            graphData[DATA_LENGTH-1] = 0;
        }
        //TODO izpisi temperaturo .. k ne vem ce sm dobr normalizeru qDebug("\n\n");
    }
    QStringList textsplit = text.split("\n");
    foreach(QString str, textsplit) {
        if(str.compare("")) {
            ui->textEdit->setPlainText( QString::number(str.toFloat()*0.1) + "\n" + ui->textEdit->toPlainText());
        //ui->textEdit->setPlainText( str + "\n" + ui->textEdit->toPlainText());
        }
    }

}

void MainWindow::ConnectError(){
    QMessageBox::warning(this, "Napaka", "Napaka v povezavi.");
    killTimer(myTimerID);
    ui->getTempButton->setText("Draw Graph");
    myTimerID = -1;
}


void MainWindow::on_getTempAllButton_clicked(){
    //ui->textEdit->clear();
    Client *client = new Client(ui->lineEditAddr->text(), ui->lineEditPort->text(), "" ,"get_temp_all", "" );
    connect(client, SIGNAL(dataReceived(QString)), this, SLOT(DataReceived(QString)));
    connect(client, SIGNAL(connectError()), this, SLOT(ConnectError()));
    client->start();
}

void MainWindow::on_getTempButton_clicked(){
    //TODO: make a trehad that calls this in intervals:
    if (myTimerID == -1){
        myTimerID=startTimer(1000*sleepInterval);
        ui->getTempButton->setText("Stop Graph");
    }else{
        killTimer(myTimerID);
        ui->getTempButton->setText("Draw Graph");
        myTimerID = -1;
    }
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
  p.setRenderHint(QPainter::Antialiasing,true);
  p.drawLine(x,y,x+width,y);
  p.drawLine(x,y+height,x+width,y+height);
  p.drawLine(x,y,x,y+height);
  p.drawLine(x+width,y,x+width,y+height);

  pp.moveTo(x,y+height);
  pp.lineTo(x,y+height-graphData[0]);
  for (i=1 ; i < DATA_LENGTH ; i++){
      pp.lineTo(x+ (int)(((float)width/((float)DATA_LENGTH-1))*i),y+height-graphData[i]);
  }
  pp.lineTo(x+width,y+height-graphData[i]);
  pp.lineTo(x+width,y+height);
  p.fillPath(pp,QBrush("#c56c00"));
}

void MainWindow::on_clearButton_clicked(){
    ui->textEdit->clear();
}

void MainWindow::timerEvent(QTimerEvent *event){
    if (event->timerId()==myTimerID && myTimerID != -1){
         this->on_getLastTempButton_clicked();
         this->update();
    }
}
