#include "tool.h"
#include <sys/time.h>
#include <iomanip>
#include <iostream>
namespace xl_tool {

//获取系统微妙
long long Tool::get_usecond() {
    timeval time;
    gettimeofday(&time, nullptr);
    return ((long long)time.tv_sec * 1e6 + time.tv_usec);
}

void Tool::Printer(int space, std::string str) {
    std::cout << std::setw(space) <<str <<  std::endl;
}
void Tool::Printer(int space, std::vector<int> vec) {

    for (const int v : vec) {
        std::cout << std::setw(space) << v ;
    }
    std::cout << std::endl;
}


}//namespace Tool
