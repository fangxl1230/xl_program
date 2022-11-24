#ifndef XL_TOOL_STRTOOL_H
#define XL_TOOL_STRTOOL_H
#include <string>
#include <vector>
namespace xl_tool {
class StrTool {
public:
    StrTool() = delete;

    /**
     * @brief 字符串分割函数
     * @param str 要分割的字符串
     * @param sep Separator，分隔符
     *
     * @return 分割后的字符串列表
     */
    static std::vector<std::string> SplitString(const std::string& str,
                                                const std::string& sep);
};

}//namespace Tool
#endif // XL_TOOL_STRTOOL_H
