//#include "xl_hci/mainwindow.h"
//#include <QApplication>

//int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();
//    return a.exec();
//}
///////////////////////////////////////////////////////////////////////////////////////////////////


// socketclint.cpp : 定义控制台应用程序的入口点。
#include <stdio.h>
#include "conio.h"
#include "windows.h"
#include "winsock.h"
#pragma comment(lib, "ws2_32.lib")

void TCPClient()
{
    //创建socket
    SOCKET sockclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (INVALID_SOCKET == sockclient)
    {
        return;
    }
    //连接服务器，建立服务器端套接字地址
    struct sockaddr_in addr = { 0 };
    addr.sin_family = AF_INET;
    addr.sin_port = htons(53);
    //对于inet_addr()函数，它是把“xxx.xxx.xxx.xxx”形式表示的IPV4地址，转换为IN_ADDR结构体能够接收的形式（unsigned long型，因为IN_ADDR结构体中的负责接收的S_addr成员变量的类型是unsigned long型）
    addr.sin_addr.S_un.S_addr = inet_addr("192.168.3.93");//本机ip

    //向服务器发出连接请求，当然我们也可以通过connet函数的返回值判断到底有无连接成功。
    int iRetVal = connect(sockclient, (struct sockaddr*)&addr, sizeof(addr));
    if (SOCKET_ERROR == iRetVal)
    {
        printf("服务器连接失败！");
        closesocket(sockclient);
        return;
    }
    printf("服务器连接成功！\n");
    //数据收发
    CHAR szSend[100] = "hello server";   //客户端  先发后收
    send(sockclient, szSend, sizeof(szSend), 0);  //发送函数，可以通过返回值判断发送成功与否。

    //接收服务器回传的数据
    CHAR szRecv[100] = { 0 };
    while (1)
    {
        int n;
        n = recv(sockclient, szRecv, 100, 0);
        if (n)//接收函数
        {
            printf("%d,%s\n",n, szRecv);//表示以字符串的格式输出服务器端发送的内容。
        }
    }
    //关闭socket
    closesocket(sockclient);
}
int main()
{
    //初始化socket库
    WSADATA wsa = { 0 };
    WSAStartup(MAKEWORD(2, 2), &wsa);
    //tcp客户端
    TCPClient();
    WSACleanup();
    return 0;
}




///////////////////////////////////////////////////////////////////////////////////////////////////


//// socketclint.cpp : 定义控制台应用程序的入口点。
//#include <stdio.h>
//#include "conio.h"
//#include "windows.h"
//#include "winsock.h"

//#pragma comment(lib, "ws2_32.lib");

////创建socket
//SOCKET sockclient;
//WSADATA wsa;
//char Rev[256];

//void TCPClientInit(int hosts, char* IPaddr)
//{
//    //初始化socket库
//    wsa = { 0 };
//    WSAStartup(MAKEWORD(2, 2), &wsa);
//    sockclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//    if (INVALID_SOCKET == sockclient)
//    {
//        printf("INVALID SOCKET!\n");
//        return;
//    }
//    //连接服务器，建立服务器端套接字地址
//    struct sockaddr_in addr = { 0 };
//    addr.sin_family = AF_INET;
//    addr.sin_port = htons(hosts);
//    //对于inet_addr()函数，它是把“xxx.xxx.xxx.xxx”形式表示的IPV4地址，转换为IN_ADDR结构体能够接收的形式（unsigned long型，因为IN_ADDR结构体中的负责接收的S_addr成员变量的类型是unsigned long型）
//    addr.sin_addr.S_un.S_addr = inet_addr(IPaddr);//本机ip

//    //向服务器发出连接请求，当然我们也可以通过connet函数的返回值判断到底有无连接成功。
//    int iRetVal = connect(sockclient, (struct sockaddr*)&addr, sizeof(addr));
//    if (SOCKET_ERROR == iRetVal)
//    {
//        printf("服务器连接失败！");
//        closesocket(sockclient);
//        return;
//    }
//    printf("服务器连接成功！\n");
//}

//void TCPSend(char* SendText,int len)//发送数据
//{
//    send(sockclient, SendText, len, 0);  //发送函数，可以通过返回值判断发送成功与否。
//}

//int TCPRescived()//接收服务器回传的数据
//{
//    int len;
//    len = recv(sockclient, Rev, 100, 0); //接收函数
//    //printf("%s\n", RevText);//表示以字符串的格式输出服务器端发送的内容。
//    return len;
//}

//void TCPClose()
//{
//    //关闭socket
//    closesocket(sockclient);
//    WSACleanup();
//}

//int main()
//{
//    //tcp客户端
//    TCPClientInit(59, "192.168.3.93");
//    int len = 0;
//    char SendText[50] = "你好啊啊啊啊啊";
//    TCPSend(SendText,strlen(SendText));
//    while (1)
//    {
//        TCPRescived();
//        printf("%s", Rev);
//    }
//    return 0;
//}
