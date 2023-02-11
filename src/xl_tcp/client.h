#ifndef XL_TCP_CLIENT_H
#define XL_TCP_CLIENT_H
#include <string>
namespace xl_tcp {

class Client {
public:
    Client(unsigned int p, std::string i);
    ~Client();


    bool Connect();
    bool DisConnect();
    bool Send(const std::string& info);
    bool Recive(const std::string& info);
//    bool Close();


    void TCPClientInit(int hosts, char* IPaddr);

    //
    int TCPRescived();
    void TCPClose();

private:
    unsigned int port;
    std::string ip;

    bool is_connect;
};

} // namespace xl_tcp
#endif // XL_TCP_CLIENT_H
