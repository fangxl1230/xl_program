#ifndef SOCKET_TOOL_H
#define SOCKET_TOOL_H

#include <QWidget>
namespace hci {
namespace Ui {
class SocketTool;
}

class SocketTool : public QWidget
{
    Q_OBJECT

public:
    explicit SocketTool(QWidget *parent = nullptr);
    ~SocketTool();

private:
    Ui::SocketTool *ui;
};
} // namespace hci
#endif // SOCKET_TOOL_H
