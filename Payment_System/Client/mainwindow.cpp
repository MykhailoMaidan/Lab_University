#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientsocket.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     socket = new ClientSocket();
    socket->InitializeClient();
    socket->ConnectClient_to_Server();
    this->setFixedSize(590,380);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(send(socket->SocketClient,"close",10,0))
    {

    }
}

void MainWindow::on_water_pushButton_clicked()
{
    if(send(socket->SocketClient,"Water",20,0))
    {

    }
    window = new Payment(socket->SocketClient,this);
    this->hide();
    window->exec();
    delete window;
    this->show();
}

void MainWindow::on_gas_pushButton_clicked()
{
    if(send(socket->SocketClient,"Gas",20,0))
    {

    }
    window = new Payment(socket->SocketClient,this);
    this->hide();
    window->exec();
    delete window;
    this->show();
}


void MainWindow::on_power_pushButton_clicked()
{
    if(send(socket->SocketClient,"Power",20,0))
    {

    }
    window = new Payment(socket->SocketClient,this);
    this->hide();
    window->exec();
    delete window;
    this->show();
}

void MainWindow::on_rubbish_pushButton_clicked()
{
    if(send(socket->SocketClient,"rubish",20,0))
    {}
    window = new Payment(socket->SocketClient,this);
    this->hide();
    window->exec();
    delete window;
    this->show();
}

void MainWindow::on__Intercom_pushButton_clicked()
{
    if(send(socket->SocketClient,"intercom",20,0))
    {}
    window = new Payment(socket->SocketClient,this);
    this->hide();
    window->exec();
    delete window;
    this->show();
}

void MainWindow::on_Internet_pushButton_clicked()
{
    if(send(socket->SocketClient,"internet",20,0))
    {}
    window = new Payment(socket->SocketClient,this);
    this->hide();
    window->exec();
    delete window;
    this->show();
}

void MainWindow::on_elevator_pushButton_clicked()
{
    if(send(socket->SocketClient,"lift",20,0))
    {}
    window = new Payment(socket->SocketClient,this);
    this->hide();
    window->exec();
    delete window;
    this->show();
}

void MainWindow::on_telephone_pushButton_clicked()
{
    if(send(socket->SocketClient,"phone",20,0))
    {}
    window = new Payment(socket->SocketClient,this);
    this->hide();
    window->exec();
    delete window;
    this->show();
}

void MainWindow::on_heating_pushButton_clicked()
{
    if(send(socket->SocketClient,"heating",20,0))
    {}
    window = new Payment(socket->SocketClient,this);
    this->hide();
    window->exec();
    delete window;
    this->show();
}

void MainWindow::on_pushButton_clicked()
{
    if(send(socket->SocketClient,"rent",20,0))
    {}
    window = new Payment(socket->SocketClient,this);
    this->hide();
    window->exec();
    delete window;
    this->show();
}
