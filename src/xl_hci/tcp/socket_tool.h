#ifndef SOCKET_TOOL_H
#define SOCKET_TOOL_H

#include <QWidget>
#include "xl_tcp/client.h"

namespace hci {
namespace Ui {
class SocketTool;
}

class SocketTool : public QWidget {
    Q_OBJECT

public:
    explicit SocketTool(QWidget *parent = nullptr);
    ~SocketTool();

private slots:
    void on_creat_client_pushButton_clicked();

    void on_clear_pushButton_clicked();

    void on_connect_pushButton_clicked();

private:
    void Update();
    void Clear();

    Ui::SocketTool *ui;

    std::shared_ptr<xl_tcp::Client> m_clents;

};
} // namespace hci
#endif // SOCKET_TOOL_H
