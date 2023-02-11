#include "tool.h"
//#include <sys/time.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <QString>
namespace xl_tool {

/** **************************************************************
 * 获取系统微妙
 ****************************************************************/
//获取系统微妙
//long long RealTimeTool::get_usecond() {
//    timeval time;
//    gettimeofday(&time, nullptr);
//    return ((long long)time.tv_sec * 1e6 + time.tv_usec);
//}

//获取linux时间
long long RealTimeTool::get_msecond() {
    return get_nsecond() / 1000;
}
long long RealTimeTool::get_usecond() {
    return get_nsecond() / 1000;
}
long long RealTimeTool::get_nsecond() {
    struct timespec t = {0, 0};
    clock_gettime(CLOCK_MONOTONIC, &t);
    return ((long long) t.tv_sec * 1e6 + t.tv_nsec);
}

/** **************************************************************
 * 转换工具
 ****************************************************************/
//任意进制转任意进制
std::string ConvertTool::ConvertToAnybit(std::string input, int in_bit, int out_bit) {
    //转十进制
    int decimal = 0;
    int num = (int)input.size() - 1;
    for (unsigned i = 0; i < input.size(); i++) {
        decimal += ((input[i] - 48) * std::pow(in_bit, num));
        num--;
    }

    std::string output = "";
    //区别进制大于10的情况
    int bit = (out_bit > 10) ? 10 : out_bit;

    int temp = decimal / out_bit;
    int left = decimal % out_bit;

    if (temp > 0) {
        output += DecimalToAnybit(std::to_string(temp), out_bit);
    }
    if (left < bit ) {
        output += (left + '0');
    }
    else {
        output += (out_bit > 10) ? ('A' + left - 10) : (left - out_bit);
    }

    return output;
}

std::string ConvertTool::DecimalToAnybit(std::string input, int out_bit) {
    std::string output = "";
    int data_int = std::atoi(input.c_str());
    //区别进制大于10的情况
    int bit = (out_bit > 10) ? 10 : out_bit;

    int temp = data_int / out_bit;
    int left = data_int % out_bit;

    if (temp > 0) {
        output += DecimalToAnybit(std::to_string(temp), out_bit);
    }
    if (left < bit ) {
        output += (left + '0');
    }
    else {
        output += (out_bit > 10) ? ('A' + left - 10) : (left - out_bit);
    }

    return output;
}


void Tool::PrintBaseDataType() {
    std::cout << "char \t\t" << sizeof (char) << std::endl;
    std::cout << "float \t\t" << sizeof (float) << std::endl;
    std::cout << "long \t\t" << sizeof (long) << std::endl;
    std::cout << "int \t\t" << sizeof (int) << std::endl;
    std::cout << "unsigned int \t" << sizeof (unsigned int) << std::endl;
    std::cout << "short int \t" << sizeof (short int) << std::endl;
    std::cout << "long int \t\t" << sizeof (long int) << std::endl;
    std::cout << "double \t\t" << sizeof (double) << std::endl;
    std::cout << "long double\t" << sizeof (long double) << std::endl;
    std::cout << "long long \t" << sizeof (long long) << std::endl;
}


void Tool::Printer(int space, std::string str) {
    std::cout << "\033[32m" << std::setw(space) << str <<  std::endl;
}
void Tool::Printer(int space, std::vector<int> vec) {

    for (const int v : vec) {
        std::cout << std::setw(space) << v ;
    }
    std::cout << std::endl;
}


}//namespace Tool
