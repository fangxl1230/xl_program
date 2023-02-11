#include "client.h"

#include <stdio.h>
#include "conio.h"
#include "windows.h"
#include "winsock.h"

namespace xl_tcp {

namespace {
//创建socket
SOCKET sockclient = { };      //
WSADATA wsa = { };            //
struct sockaddr_in addr = {}; //连接服务器，建立服务器端套接字地址
char Rev[256];
}

Client::Client(unsigned int p, std::string i) :
    port(p),
    ip(i),
    is_connect(false){
    //初始化socket库
    WSAStartup(MAKEWORD(2, 2), &wsa);

    //创建socket
    sockclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (INVALID_SOCKET == sockclient) {
        return;
    }
    //连接服务器，建立服务器端套接字地址
    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    //对于inet_addr()函数，它是把“xxx.xxx.xxx.xxx”形式表示的IPV4地址，转换为IN_ADDR结构体能够接收的形式（unsigned long型，因为IN_ADDR结构体中的负责接收的S_addr成员变量的类型是unsigned long型）
    addr.sin_addr.S_un.S_addr = inet_addr(ip.data());//本机ip

    //向服务器发出连接请求，当然我们也可以通过connet函数的返回值判断到底有无连接成功。
    int iRetVal = connect(sockclient, (sockaddr*)&addr, sizeof(addr));
    if (SOCKET_ERROR == iRetVal) {
        printf("服务器连接失败！");
        closesocket(sockclient);
        return;
    }
    printf("服务器连接成功！\n");
    //数据收发
    CHAR szSend[100] = "hello server";   //客户端  先发后收
    send(sockclient, szSend, sizeof(szSend), 0);  //发送函数，可以通过返回值判断发送成功与否。
//    //接收服务器回传的数据
//    CHAR szRecv[100] = { 0 };
//    while (1) {
//        int n;
//        n = recv(sockclient, szRecv, 100, 0);
//        if (n)//接收函数
//        {
//            printf("%d,%s\n",n, szRecv);//表示以字符串的格式输出服务器端发送的内容。
//        }
//    }
//    //关闭socket
//    closesocket(sockclient);


//    //初始化socket库
//    WSAStartup(MAKEWORD(2, 2), &wsa);
//    sockclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//    if (INVALID_SOCKET == sockclient) {
//        printf("INVALID SOCKET!\n");
//        return;
//    }
//    //连接服务器，建立服务器端套接字地址
//    addr.sin_family = AF_INET;
//    addr.sin_port = htons(port);
//    //对于inet_addr()函数，它是把“xxx.xxx.xxx.xxx”形式表示的IPV4地址，转换为IN_ADDR结构体能够接收的形式（unsigned long型，因为IN_ADDR结构体中的负责接收的S_addr成员变量的类型是unsigned long型）
//    addr.sin_addr.S_un.S_addr = inet_addr(ip.data());//本机ip
//    //向服务器发出连接请求，当然我们也可以通过connet函数的返回值判断到底有无连接成功。
//    int iRetVal = connect(sockclient, (struct sockaddr*)&addr, sizeof(addr));
//    if (SOCKET_ERROR == iRetVal) {
//        printf("服务器连接失败！");
//        closesocket(sockclient);
//        is_connect = false;
//    }
//    else {
//        is_connect = true;
//        printf("服务器连接成功！\n");
//    }
}
Client::~Client() {
    //关闭socket
    closesocket(sockclient);
    WSACleanup();
}

bool Client::Connect() {
    //向服务器发出连接请求，当然我们也可以通过connet函数的返回值判断到底有无连接成功。
    int iRetVal = connect(sockclient, (struct sockaddr*)&addr, sizeof(addr));
    if (SOCKET_ERROR == iRetVal) {
        printf("服务器连接失败！");
        closesocket(sockclient);
        return false;
    }
    printf("服务器连接成功！\n");
    return true;
}
bool Client::DisConnect() {

}
//bool Client::Close() {
//    //关闭socket
//    closesocket(sockclient);
//    WSACleanup();
//}
bool Client::Send(const std::string& info) {

}
bool Client::Recive(const std::string& info) {

}


//void Client::TCPClientInit(int hosts, char* IPaddr) {

//}

//接收服务器回传的数据
int Client::TCPRescived() {
    int len;
    len = recv(sockclient, Rev, 100, 0); //接收函数
    //printf("%s\n", RevText);//表示以字符串的格式输出服务器端发送的内容。
    return len;
}


} // namespace xl_tcp
