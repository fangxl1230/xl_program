#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "math/math.h"
#include "tool/tool.h"

#include <iostream>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

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
