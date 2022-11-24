#include "tcp.h"
#include "ui_tcp.h"
#include "xl_tcp/client.h"
#include "xl_tcp/sever.h"

namespace hci {
TCP::TCP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TCP) {
    ui->setupUi(this);
}

TCP::~TCP() {
    delete ui;
}

void TCP::on_connect_pushButton_clicked() {

}
void TCP::on_client_send_pushButton_clicked() {

}
void TCP::on_client_recive_pushButton_clicked() {

}

void TCP::on_monitor_pushButton_clicked() {

}
void TCP::on_sever_send_pushButton_clicked() {

}
void TCP::on_sever_recive_pushButton_clicked() {

}

} // namespace hci




