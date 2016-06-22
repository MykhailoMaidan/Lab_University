#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "matrix.h"
#include <QMainWindow>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_spinBox_matrix_valueChanged(int arg1);

    void on_save_close_pushButton_clicked();

    void on_AcceptSize_clicked();

    void on_SaveLine_clicked();

    void on_Result_clicked();

    void on_Random_button_clicked();

    void ShowRes(Matrix &);



    void on_Reset_button_clicked();

private:
    int count;
    int count_2;
    Ui::MainWindow *ui;
    Matrix matrix_A;
    Matrix matrix_C;
    Matrix matrix_B;
    Matrix matrix_A1;
    Matrix matrix_B1;
    Matrix matrix_b;
    Matrix matrixb;
    Matrix matrix_c;
    Matrix matrix_y1;
    Matrix matrix_y2;
    Matrix matrix_Y3;
    QTableWidgetItem* itm;


};

#endif // MAINWINDOW_H
