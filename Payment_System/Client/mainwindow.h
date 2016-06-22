#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "payment.h"
#include "clientsocket.h"

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
    void on_water_pushButton_clicked();

    void on_gas_pushButton_clicked();

    void on_power_pushButton_clicked();

    void on_rubbish_pushButton_clicked();

    void on__Intercom_pushButton_clicked();

    void on_Internet_pushButton_clicked();

    void on_elevator_pushButton_clicked();

    void on_telephone_pushButton_clicked();

    void on_heating_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Payment* window;
    ClientSocket* socket;


};

#endif // MAINWINDOW_H
