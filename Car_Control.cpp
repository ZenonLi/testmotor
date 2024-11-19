#include "Car_Control.h"
#include "ui_Car_Control.h"
#include <QDebug>
Car_Control::Car_Control(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Car_Control)
{
    ui->setupUi(this);
    socket = new QTcpSocket;
}

Car_Control::~Car_Control()
{
    delete ui;
    delete socket;
}


void Car_Control::on_Bt_connect_clicked()
{
    if (ui->lineEdit_IP->text().isEmpty() || ui->lineEdit_Port->text().isEmpty()){
        qDebug() << "IP地址不完整";
        return;
    }else{
        qDebug() << "可以连接";
    }
    QString ip = ui->lineEdit_IP->text();
    int port = ui->lineEdit_Port->text().toInt();
    socket->connectToHost(ip, port);
}

void Car_Control::on_Bt_disconnect_clicked()
{
    socket->disconnectFromHost();
}

void Car_Control::on_Bt_forward_clicked()
{
    char msg[] = "forward";
    socket->write(msg, sizeof(msg));
}

void Car_Control::on_Bt_stop_clicked()
{
    char msg[] = "stop";
    socket->write(msg, sizeof(msg));
}

void Car_Control::on_Bt_back_clicked()
{
    char msg[] = "back";
    socket->write(msg, sizeof(msg));
}

void Car_Control::on_Bt_turnleft_clicked()
{
    char msg[] = "left";
    socket->write(msg, sizeof(msg));
}

void Car_Control::on_Bt_turnright_clicked()
{
    char msg[] = "right";
    socket->write(msg, sizeof(msg));
}

void Car_Control::on_Bt_trace_clicked()
{
    if (ui->Bt_trace->text() == "启动" ){
        ui->Bt_back->setEnabled(false);
        ui->Bt_stop->setEnabled(false);
        ui->Bt_forward->setEnabled(false);
        ui->Bt_turnleft->setEnabled(false);
        ui->Bt_turnright->setEnabled(false);
        ui->Bt_trace->setText("关闭");
        char msg[] = "trace_on";
        socket->write(msg, sizeof(msg));
    }else{
        ui->Bt_back->setEnabled(true);
        ui->Bt_stop->setEnabled(true);
        ui->Bt_forward->setEnabled(true);
        ui->Bt_turnleft->setEnabled(true);
        ui->Bt_turnright->setEnabled(true);
        ui->Bt_trace->setText("启动");
        char msg[] = "trace_off";
        socket->write(msg, sizeof(msg));
    }
}

void Car_Control::on_Bt_avoiding_clicked()
{
    if (ui->Bt_avoiding->text() == "启动" ){
        ui->Bt_back->setEnabled(false);
        ui->Bt_stop->setEnabled(false);
        ui->Bt_forward->setEnabled(false);
        ui->Bt_turnleft->setEnabled(false);
        ui->Bt_turnright->setEnabled(false);
        ui->Bt_avoiding->setText("关闭");
        char msg[] = "avoiding_on";
        socket->write(msg, sizeof(msg));
    }else{
        ui->Bt_back->setEnabled(true);
        ui->Bt_stop->setEnabled(true);
        ui->Bt_forward->setEnabled(true);
        ui->Bt_turnleft->setEnabled(true);
        ui->Bt_turnright->setEnabled(true);
        ui->Bt_avoiding->setText("启动");
        char msg[] = "avoiding_off";
        socket->write(msg, sizeof(msg));
    }
}
