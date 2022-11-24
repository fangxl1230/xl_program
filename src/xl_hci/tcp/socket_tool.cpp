#include "socket_tool.h"
#include "ui_socket_tool.h"
namespace hci {
SocketTool::SocketTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SocketTool)
{
    ui->setupUi(this);
}

SocketTool::~SocketTool()
{
    delete ui;
}
} // namespace hci
