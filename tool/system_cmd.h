#ifndef SYSTEMCMD_H
#define SYSTEMCMD_H
#include <string>
#include <vector>
namespace xl_tool {
class SystemCmd {
public:
    SystemCmd() = delete;


    /**
     * @brief 执行终端指令
     * @param instruction 终端指令字符串
     * @param error_info  输出错误信息
     *
     * @return true执行成功
     */
    static bool ExecuteSysInstruction (const std::string& instruction, std::string& error_info);
    /**
     * @brief 获取终端指令执行后的字符串
     * @param instruction 终端指令字符串
     * @param error_info  输出错误信息
     *
     * @return 终端指令执行后的字符串
     */
    static bool GetTerminalExecuteInfo(const std::string& instruction, std::vector<std::string>& output_values, std::string& error_info);

};
}//namespace Tool
#endif // SYSTEMCMD_H
