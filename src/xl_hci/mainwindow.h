#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "process_control.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
namespace hci {
class HexConvert;
}


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void RunLoop();

    //日常练习
    void on_leetcode_button_clicked();
    void on_tcp_pushButton_clicked();

    //工具
    void on_hex_convert_button_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* m_update_systime_thread;



    ProcessControl* m_process_control;


};
#endif // MAINWINDOW_H
