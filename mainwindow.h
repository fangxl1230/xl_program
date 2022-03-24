#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "process_control.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void RunLoop();

private:
    Ui::MainWindow *ui;
    QTimer* m_update_systime_thread;

    ProcessControl* m_process_control;


};
#endif // MAINWINDOW_H
