#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
//日常练习
#include "leetcode/leetcode.h"
#include "tcp/socket_tool.h"
#include "tcp/tcp.h"
//工具
#include "hex_convert.h"

#include "xl_spm/math/mathematical.h"
#include "xl_tool/tool.h"

#include <iostream>
#include <vector>
#include <qdebug.h>

namespace {
//日常练习
hci::LeetCode* leet_code = nullptr;
hci::TCP* tcp = nullptr;
hci::SocketTool* socket_tool = nullptr;
//工具
hci::HexConvert* hex_convert = nullptr;

}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);


    leet_code = new hci::LeetCode();
    socket_tool = new hci::SocketTool();
    tcp = new hci::TCP();

    hex_convert = new hci::HexConvert();
//    connect(hex_convert, hex_convert->show(), on_hex_convert_button_clicked(), this);

    //设置循环周期
    m_update_systime_thread = new QTimer();
    m_update_systime_thread->setInterval(1000);
    connect(m_update_systime_thread, SIGNAL(timeout()), this, SLOT(RunLoop()));
    m_update_systime_thread->start();

    m_process_control = new ProcessControl();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::RunLoop() {
    m_process_control->RunLoop();
}

//日常练习
void MainWindow::on_leetcode_button_clicked(){
    leet_code->Init();
    leet_code->show();
}
void MainWindow::on_tcp_pushButton_clicked() {
//    tcp->show();

    socket_tool->show();

}

//工具
void MainWindow::on_hex_convert_button_clicked() {
    std::cout << "进制转换" << std::endl;
    hex_convert->show();
}
