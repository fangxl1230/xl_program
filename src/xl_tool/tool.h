#ifndef TOOL_H
#define TOOL_H
#include <string>
#include <vector>

namespace xl_tool {
/**
 * @brief 获取系统微妙
 */
class RealTimeTool {
    RealTimeTool() = delete;

    static long long get_msecond();
    static long long get_usecond();
    static long long get_nsecond();
};

/**
 * @brief 转换工具
 */
class ConvertTool {
    ConvertTool() = delete;
public:
    /**
     * @brief 任意进制转任意进制
     * @param input   输入数据
     * @param in_bit  输入进制
     * @param out_bit 输出进制
     * @return 输入数据
     */
    static std::string ConvertToAnybit(std::string input, int in_bit, int out_bit);
    /**
     * @brief 任意进制转任意进制
     * @param input   输入数据
     * @param in_bit  输入进制
     * @param out_bit 输出进制
     * @return 输入数据
     */
    static std::string DecimalToAnybit(std::string input, int out_bit);


};


class Tool {
public:
    Tool() = delete;

    static void PrintBaseDataType();


/** ********************************************************************
 *  字符串类
 *********************************************************************/
    static void Printer(int space, std::string str);
    static void Printer(int space, std::vector<int> vec);


};
}//namespace Tool
#endif // TOOL_H
