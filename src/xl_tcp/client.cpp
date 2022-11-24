#include "client.h"

#include <stdio.h>
#include "conio.h"
#include "windows.h"
#include "winsock.h"

namespace xl_tcp {
Client::Client(unsigned int p, std::string i) :
    port(p),
    ip(i) {

}
namespace {
//创建socket
SOCKET sockclient;
WSADATA wsa;
char Rev[256];
}
void Client::TCPClientInit(int hosts, char* IPaddr) {
    //初始化socket库
    wsa = { 0 };
    WSAStartup(MAKEWORD(2, 2), &wsa);
    sockclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (INVALID_SOCKET == sockclient) {
        printf("INVALID SOCKET!\n");
        return;
    }
    //连接服务器，建立服务器端套接字地址
    struct sockaddr_in addr = { 0 };
    addr.sin_family = AF_INET;
    addr.sin_port = htons(hosts);
    //对于inet_addr()函数，它是把“xxx.xxx.xxx.xxx”形式表示的IPV4地址，转换为IN_ADDR结构体能够接收的形式（unsigned long型，因为IN_ADDR结构体中的负责接收的S_addr成员变量的类型是unsigned long型）
    addr.sin_addr.S_un.S_addr = inet_addr(IPaddr);//本机ip

    //向服务器发出连接请求，当然我们也可以通过connet函数的返回值判断到底有无连接成功。
    int iRetVal = connect(sockclient, (struct sockaddr*)&addr, sizeof(addr));
    if (SOCKET_ERROR == iRetVal) {
        printf("服务器连接失败！");
        closesocket(sockclient);
        return;
    }
    printf("服务器连接成功！\n");
}

//接收服务器回传的数据
int Client::TCPRescived() {
    int len;
    len = recv(sockclient, Rev, 100, 0); //接收函数
    //printf("%s\n", RevText);//表示以字符串的格式输出服务器端发送的内容。
    return len;
}

void Client::TCPClose() {
    //关闭socket
    closesocket(sockclient);
    WSACleanup();
}
} // namespace xl_tcp
