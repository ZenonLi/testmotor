#ifndef CAR_CONTROL_H
#define CAR_CONTROL_H

#include <QWidget>
#include <QTcpSocket>
QT_BEGIN_NAMESPACE
namespace Ui { class Car_Control; }
QT_END_NAMESPACE

class Car_Control : public QWidget
{
    Q_OBJECT

public:
    Car_Control(QWidget *parent = nullptr);
    ~Car_Control();

private slots:
    void on_Bt_connect_clicked();
    void on_Bt_disconnect_clicked();
    void on_Bt_forward_clicked();
    void on_Bt_stop_clicked();
    void on_Bt_back_clicked();
    void on_Bt_turnleft_clicked();
    void on_Bt_turnright_clicked();

    void on_Bt_trace_clicked();

    void on_Bt_avoiding_clicked();

private:
    Ui::Car_Control *ui;
    QTcpSocket* socket;

};
#endif // CAR_CONTROL_H
