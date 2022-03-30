#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "hci/hex_convert.h"
#include "math/math.h"
#include "tool/tool.h"

#include <iostream>
#include <vector>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

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

void MainWindow::on_hex_convert_button_clicked() {
    std::cout << "进制转换" << std::endl;
    QString s = "进制转换";
    hex_convert->show();
//    std::cout << s.toStdString() << std::endl;

}
