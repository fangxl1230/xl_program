#ifndef TCP_H
#define TCP_H

#include <QWidget>
namespace hci {
namespace Ui {
class TCP;
}

class TCP : public QWidget {
    Q_OBJECT

public:
    explicit TCP(QWidget *parent = nullptr);
    ~TCP();

private slots:
    void on_connect_pushButton_clicked();
    void on_client_send_pushButton_clicked();
    void on_client_recive_pushButton_clicked();

    void on_monitor_pushButton_clicked();
    void on_sever_send_pushButton_clicked();
    void on_sever_recive_pushButton_clicked();

private:
    Ui::TCP *ui;
};
} // namespace hci
#endif // TCP_H
