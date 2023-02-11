#include "socket_tool.h"
#include "ui_socket_tool.h"
#include "xl_tcp/client.h"

#include "xl_tool/str_tool.h"
#pragma comment(lib, "ws2_32.lib");

namespace hci {
SocketTool::SocketTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SocketTool) {
    ui->setupUi(this);
}

SocketTool::~SocketTool() {
    delete ui;
}

namespace {
std::string error_info = "";
xl_tcp::Client *client = nullptr;
bool CheckIPAndPort(const std::string& ip, const std::string& port) {
    if (port.empty() || ip.empty()){
        error_info += "ip或port为空，请输入ip或port";
        return false;
    }
    int ppp = std::atoi(port.c_str());
    if (ppp < 0 && ppp > 999999) {
        error_info = "请重新输入port。";
    }

    std::vector<std::string> ip_list = xl_tool::StrTool::SplitString(ip, ".");
    for (unsigned int i = 0; i < 4; i++) {
        int iii = std::atoi(ip_list[i].c_str());
        if (iii < 1 && iii > 255) {
            error_info += "IP格式不正确。";
            break;
        }
    }
    return error_info.empty() ? true : false;
}

}
void SocketTool::on_creat_client_pushButton_clicked() {
    //清空错误栏
    ui->error_info_lineEdit->clear();
    error_info.clear();


    std::string port_str = ui->client_port_lineEdit->text().toStdString();
    std::string ip_str = ui->client_ip_lineEdit->text().toStdString();

    if (!CheckIPAndPort(ip_str, port_str)) {
        Update();
        return;
    }

    client = new xl_tcp::Client(std::atoi(port_str.c_str()), ip_str);

    int a = 0;


}

void SocketTool::on_connect_pushButton_clicked() {
    if (!client->Connect()) {
        error_info += "connect faild";
    }
    update();
}

void SocketTool::on_clear_pushButton_clicked() {
    Clear();
}

void SocketTool::Update() {
    if (!error_info.empty()) {
        ui->error_info_lineEdit->setText(QString::fromLocal8Bit(error_info.data()));
    }
}

void SocketTool::Clear() {
    ui->error_info_lineEdit->clear();
}

} // namespace hci







