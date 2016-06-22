#ifndef PAYMENT_H
#define PAYMENT_H

#include <QDialog>
#include <winsock2.h>

namespace Ui {
class Payment;
}

class Payment : public QDialog
{
    Q_OBJECT

public:
    explicit Payment(SOCKET, QWidget *parent = 0 );
    ~Payment();

private slots:
    void on_Payment_pushButton_clicked();

    void on_Pay_clicked();

private:
    Ui::Payment *ui;
    SOCKET db;
    char data[1000];
    int number;
};

#endif // PAYMENT_H
