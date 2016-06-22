#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    itm = new QTableWidgetItem();
     ui->setupUi(this);
   this->setWindowTitle("Matrix");
   this->setFixedSize(738,610);
   count = 0;
   count_2 = 0;
   ui->radok_tablewidget->setRowCount(1);
   ui->groupBox->setTitle("Matrix A");
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_spinBox_matrix_valueChanged(int arg1)
{
    ui->tableWidget_matrix->setRowCount(arg1);
    ui->tableWidget_matrix->setColumnCount(arg1);
    ui->radok_tablewidget->setColumnCount(arg1);
}
void MainWindow::on_save_close_pushButton_clicked()
{
    count++;
    switch(count)
    {
    case 1:
        ui->groupBox->setTitle("Matrix A1");
        break;
    case 2:
         ui->groupBox->setTitle("Matrix A2");
         break;
    case 3:
         ui->groupBox->setTitle("Matrix B2");
        break;
    }
    float** mass_matrix = new float* [ui->tableWidget_matrix->rowCount()];
    for(int i = 0; i < ui->tableWidget_matrix->rowCount(); i++)
    {
        mass_matrix[i] = new float[ui->tableWidget_matrix->columnCount()];
    }
     for(int i = 0; i < ui->tableWidget_matrix->rowCount(); i++)
    {
        for (int j = 0; j < ui->tableWidget_matrix->columnCount(); j++)
        {
                    itm = ui->tableWidget_matrix->item(i,j);
                    mass_matrix[i][j] = itm->text().toFloat();
        }
    }
    switch(count)
    {
    case 1:
         matrix_A.SetData(ui->tableWidget_matrix->rowCount(),ui->tableWidget_matrix->columnCount(),mass_matrix);
         break;
    case 2:
        matrix_B.SetData(ui->tableWidget_matrix->rowCount(),ui->tableWidget_matrix->columnCount(),mass_matrix);
         break;
    case 3:
        matrix_A1.SetData(ui->tableWidget_matrix->rowCount(),ui->tableWidget_matrix->columnCount(),mass_matrix);
         break;
    case 4:
        matrix_B1.SetData(ui->tableWidget_matrix->rowCount(),ui->tableWidget_matrix->columnCount(),mass_matrix);
         break;
    }
    if(count == 4)
    {
        ui->tableWidget_matrix->setEnabled(false);
        ui->save_close_pushButton->setEnabled(false);
    }
    ui->tableWidget_matrix->clear();

}
void MainWindow::on_AcceptSize_clicked()
{
    ui->tableWidget_matrix->setColumnCount(ui->spinBox_matrix->value());
    ui->tableWidget_matrix->setRowCount(ui->spinBox_matrix->value());
    ui->spinBox_matrix->setEnabled(false);
    ui->AcceptSize->setEnabled(false);
}
void MainWindow::on_SaveLine_clicked()
{
    count_2++;
    if(count_2 == 1)
    {
      ui->label_2->setText("Line c1");
    }
    float** mass_matrix_1 = new float*[1];
    bool asd= 0;
    for(int i = 0; i < ui->radok_tablewidget->rowCount(); i++)
    {
        mass_matrix_1[i] = new float[ui->radok_tablewidget->columnCount()];
    }
    for (int j = 0; j < ui->radok_tablewidget->columnCount(); j++)
        {
                  itm = (ui->radok_tablewidget->item(0,j));
                  QString sdwe = itm->text();
                  mass_matrix_1[0][j] = sdwe.toFloat();
        }
    switch (count_2) {
    case 1:
        matrixb.SetData(1,ui->radok_tablewidget->columnCount(),mass_matrix_1);
        break;
    case 2:
        matrix_c.SetData(1,ui->radok_tablewidget->columnCount(),mass_matrix_1);
        break;
   }
    if(count_2 == 2)
    {
        ui->radok_tablewidget->setEnabled(false);
        ui->SaveLine->setEnabled(false);
    }
    ui->radok_tablewidget->clear();
    for(int i = 0; i < ui->radok_tablewidget->rowCount(); i++)
    delete[] mass_matrix_1[ui->radok_tablewidget->columnCount()];
}

void MainWindow::on_Result_clicked()
{
    //-------------------------------------------------------
  matrix_b.Stobu(ui->spinBox_matrix->value(),1);
  matrix_b.ShowFile();
  matrix_y1 = matrix_A*matrix_b;
  matrix_y1.ShowFile();
    //-------------------------------------------------------
  matrix_y2 =  matrixb.NumberAddMatrix(12);
  matrix_y2 = matrix_y2 * matrix_A1;
  Matrix res = matrix_c.NumberAddMatrix(3);
  res.ShowFile();
  matrix_y2 = matrix_y2-res;
  matrix_y2.ShowFile();
  matrix_C.GenericMatrixC(ui->spinBox_matrix->value());
  matrix_C.ShowFile();
  Matrix res_1 = matrix_A1.NumberAddMatrix(2);
  res_1.ShowFile();
  Matrix res2 = matrix_B.NumberAddMatrix(3);
  res2.ShowFile();
  Matrix res3 = matrix_C.NumberAddMatrix(5);
  res3.ShowFile();
  matrix_Y3 = res_1+res2-res3;
  Matrix SQRmatrix = matrix_Y3*matrix_Y3;
  SQRmatrix = SQRmatrix*matrix_y1;
  SQRmatrix.ShowFile();
  Matrix trans_matrix = matrix_y2.setTransMatrix();
  trans_matrix.ShowFile();
  SQRmatrix = SQRmatrix + trans_matrix;
  SQRmatrix.ShowFile();
  SQRmatrix = SQRmatrix*matrix_y1;
  SQRmatrix.ShowFile();
  Matrix trans_y1 = matrix_y1.setTransMatrix();
  SQRmatrix = trans_y1 * SQRmatrix;
  SQRmatrix.ShowFile();
  Matrix y1y_2y1 = matrix_y1*trans_matrix;
  y1y_2y1.ShowFile();
  y1y_2y1 = y1y_2y1*matrix_y1;
  y1y_2y1.ShowFile();
  SQRmatrix = SQRmatrix.ADDNumberMatrix(y1y_2y1);
  SQRmatrix.ShowFile();
  Matrix RES_1 = SQRmatrix*matrix_y2;
  RES_1.ShowFile();
  SQRmatrix = matrix_Y3-RES_1;
  SQRmatrix.ShowFile();
  SQRmatrix = matrix_y2*SQRmatrix;
  SQRmatrix.ShowFile();
  ShowRes(SQRmatrix);
}
void MainWindow::on_Random_button_clicked()
{
    int random = rand()%100;
    for(int i = 0; i < ui->spinBox_matrix->value(); i++)
    {
        for (int  j = 0; j < ui->spinBox_matrix->value(); j++)
        {
            if(!ui->tableWidget_matrix->isEnabled())
            {
                break;
            }
             itm = new QTableWidgetItem(tr("%1").arg(random));
            random = rand()%100;
            ui->tableWidget_matrix->setItem(i,j,itm);
        }
    }
int randon= 0;
        for (int  j = 0; j < ui->spinBox_matrix->value(); j++)
        {
            if(!ui->radok_tablewidget->isEnabled())
            {
                break;
            }
            randon = rand()%100;
            itm = new QTableWidgetItem(tr("%3").arg(randon));
            ui->radok_tablewidget->setItem(0,j,itm);
        }
}
void MainWindow::ShowRes(Matrix &obj)
{
    ui->res_tableWidget->setRowCount(obj.ShowRow());
    ui->res_tableWidget->setColumnCount(obj.ShowCollum());
    float **mass = new float*[obj.ShowRow()];
    float **mass_1 = obj.ShowMatrix();
    for (int i = 0; i < obj.ShowRow(); i++)
    {
        mass[i] = new float [obj.ShowCollum()] ;
    }
    for (int i = 0; i < obj.ShowRow(); i++)
    {
        for (int j = 0; j < obj.ShowCollum(); j++)
        {
             mass[i][j] = mass_1[i][j];
        }
    }
    for(int i = 0; i < ui->res_tableWidget->rowCount(); i++)
    {
        for(int j = 0; j < ui->res_tableWidget->columnCount(); j++)
        {
            float count = mass[i][j];
              QTableWidgetItem *it = new QTableWidgetItem(tr("%1").arg(count));
              ui->res_tableWidget->setItem(i,j,it);
        }
    }
    ui->tableWidget_matrix->reset();
}
void MainWindow::on_Reset_button_clicked()
{
    count = 0;
    count_2 = 0;
    ui->tableWidget_matrix->setEnabled(true);
    ui->radok_tablewidget->setEnabled(true);
    ui->SaveLine->setEnabled(true);
    ui->spinBox_matrix->setEnabled(true);
    ui->AcceptSize->setEnabled(true);
    ui->save_close_pushButton->setEnabled(true);

}
