#include "payment.h"
#include "ui_payment.h"
#include <QMessageBox>

Payment::Payment(SOCKET obj, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Payment)
{
    ui->setupUi(this);
    db = obj;
    ui->Pay->setEnabled(false);
    this->setFixedSize(470,334);
}

Payment::~Payment()
{
    delete ui;
    if(send(db,"close",10,0))
    {

    }
}

void Payment::on_Payment_pushButton_clicked()
{
    ui->textBrowser->clear();
   if(send(db,ui->lineEdit->text().toStdString().c_str(), ui->lineEdit->text().length()+1,0))
   {

    }
        memset(data,0,sizeof(data));
        if(recv(db,data,1000,0))
        {

        }
        if(strcmp(data,"0") == false)
        {

            QMessageBox::information(this,"information", "Нічого не знайдено. Введіть коректні дані!");
            ui->Pay->setEnabled(false);
        }
        else
        {


        char* point = strtok(data,"-");
        while(point != NULL)
        {
            if(atoi(point))
            {
                number = atoi(point);
            }
            ui->textBrowser->append(QString(point));
            point = strtok(NULL, "-");

        }
        ui->Pay->setEnabled(true);
        }
}

void Payment::on_Pay_clicked()
{
    if(ui->lineEdit_2->text() == 0)
    {
        QMessageBox::information(this,"Information","Error. Nothing entered");
    }
    else
    {
    if(send(db, "pay",5,0))
    {

    }
    if(send(db, ui->lineEdit_2->text().toStdString().c_str(),ui->lineEdit_2->text().length(),0))
    {

    }
    memset(data,0,sizeof(data));
    if(recv(db,data,100,0))
    {

    }
    QMessageBox::information(this,"Інформація",QString(data));
    }

}
