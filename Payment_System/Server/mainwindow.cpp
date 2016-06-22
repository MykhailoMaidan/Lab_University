#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <socketserver.h>
#include <windows.h>
#include "serverthread.h"

#include <QSqlQuery>
#include <QDialog>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new SocketServer();
    server->InitializeSocket();
    server->BindSocket();
    server->ListhenSocket();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Connect_clicked()  // connect to database
{
        db =  QSqlDatabase::addDatabase("QMYSQL");
        db.setDatabaseName("ipz_hubish");
        //db.setHostName("127.0.0.0");
        //db.setPort(3306);
        db.setUserName("root");
        db.setPassword("root");
        if(db.open())
        {
                ui->Status->setText("Connect success;");
        }
        else
        {
            ui->Status->setText("Connect fail;");
        }
    }



void MainWindow::on_DataBaseUser_button_clicked() // show the database users
{
        model =  new QSqlTableModel(this,db);
        model->setTable("Water");
        model->select();
        ui->Table->setModel(model);

}



void MainWindow::on_ShowDataBaseBook_button_clicked() //show database books
{
    model =  new QSqlTableModel(this,db);
    model->setTable("gass");
    model->select();
    ui->Table->setModel(model);
}




void MainWindow::on_Start_Server_button_clicked() // server start working
{
    server->DBtoSock(&db);
    ServerThread* Thread = new ServerThread(server);
    Thread->start();

}


void MainWindow::on_pushButton_clicked()
{
    model =  new QSqlTableModel(this,db);
    model->setTable("power");
    model->select();
    ui->Table->setModel(model);
}

void MainWindow::on_ShowDataBaseBook_button_2_clicked()
{
    model =  new QSqlTableModel(this,db);
    model->setTable("elevator");
    model->select();
    ui->Table->setModel(model);
}

void MainWindow::on_ShowDataBaseBook_button_3_clicked()
{
    model =  new QSqlTableModel(this,db);
    model->setTable("rubbish");
    model->select();
    ui->Table->setModel(model);
}

void MainWindow::on_ShowDataBaseBook_button_4_clicked()
{
    model =  new QSqlTableModel(this,db);
    model->setTable("rent");
    model->select();
    ui->Table->setModel(model);
}

void MainWindow::on_ShowDataBaseBook_button_5_clicked()
{
    model =  new QSqlTableModel(this,db);
    model->setTable("heating");
    model->select();
    ui->Table->setModel(model);
}

void MainWindow::on_ShowDataBaseBook_button_6_clicked()
{
    model =  new QSqlTableModel(this,db);
    model->setTable("intercom");
    model->select();
    ui->Table->setModel(model);
}

void MainWindow::on_ShowDataBaseBook_button_7_clicked()
{

    model =  new QSqlTableModel(this,db);
    model->setTable("internet");
    model->select();
    ui->Table->setModel(model);
}

void MainWindow::on_ShowDataBaseBook_button_8_clicked()
{

    model =  new QSqlTableModel(this,db);
    model->setTable("phone");
    model->select();
    ui->Table->setModel(model);
}
