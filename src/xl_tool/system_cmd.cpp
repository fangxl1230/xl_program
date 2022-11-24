#include "system_cmd.h"
#include <unistd.h>
#include <dirent.h>
namespace xl_tool {

//执行终端指令
bool SystemCmd::ExecuteSysInstruction (const std::string& instruction, std::string& error_info) {
    pid_t status = system(instruction.c_str());
    if(status == -1) {
        error_info = "执行" + instruction + "时，" + strerror(errno);
        return false;
    }
    else {
        //WIFEXITED(status) 用来指出子进程是否为正常退出的，如果是，它会返回一个非零值
        //WEXITSTATUS(status) 用来获取返回值status的低8~15数据
//        if(WIFEXITED(status)) {
//            if(WEXITSTATUS(status) != 0) {
//                error_info = std::to_string(status) + " : " + strerror(errno);
//                return false;
//            }
//        }
//        else {
//            error_info = std::to_string(status) + " : " + strerror(errno);
//            return false;
//        }
    }
    return true;
}

//获取终端指令执行后的字符串
bool SystemCmd::GetTerminalExecuteInfo (const std::string& instruction, std::vector<std::string>& output_values, std::string& error_info) {
    //建立管道
    FILE *fp = nullptr;
    if (!(fp = popen(instruction.c_str(), "r"))) {
        error_info = "执行" + instruction + "建立管道error!!!";
        return false;
    }
    char read_str[1024] = "";
    while (fgets(read_str, sizeof(read_str), fp)) {
        if (read_str[strlen(read_str) - 1] == '\n') {
            read_str[strlen(read_str) - 1] = '\0'; //去除换行符
        }
        output_values.push_back(read_str);
    }
    //关闭管道
    pclose(fp);
    return true;
}

}//namespace Tool
