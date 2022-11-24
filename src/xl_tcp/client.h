#ifndef XL_TCP_CLIENT_H
#define XL_TCP_CLIENT_H
#include <string>
namespace xl_tcp {

class Client {
public:
    Client(unsigned int p, std::string i);
    ~Client() {}

    void TCPClientInit(int hosts, char* IPaddr);

    //接收服务器回传的数据
    int TCPRescived();
    void TCPClose();

private:
    unsigned int port;
    std::string ip;
};

} // namespace xl_tcp
#endif // XL_TCP_CLIENT_H
