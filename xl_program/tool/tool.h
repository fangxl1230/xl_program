#ifndef TOOL_H
#define TOOL_H
#include <string>
#include <vector>

namespace xl_tool {
class Tool {
public:
    Tool() = delete;


/** ********************************************************************
 *  时间类
 *********************************************************************/
    /**
     * @brief 获取系统微妙
     */
    static long long get_usecond();

/** ********************************************************************
 *  字符串类
 *********************************************************************/
    static void Printer(int space, std::string str);
    static void Printer(int space, std::vector<int> vec);


};
}//namespace Tool
#endif // TOOL_H
