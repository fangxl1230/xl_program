#include "str_tool.h"
namespace xl_tool {

//字符串分割函数
std::vector<std::string> StrTool::SplitString(const std::string& str,
                                              const std::string& sep) {
    std::vector<std::string> res;
    //pos1起时位置，pos2下一个sep的起时位置
    std::string::size_type pos1 = 0, pos2 = str.find(sep);
    while(std::string::npos != pos2) {
        res.push_back(str.substr(pos1, pos2 - pos1));
        pos1 = pos2 + sep.size();
        pos2 = str.find(sep, pos1);
    }
    if(pos1 != str.length()) {
        res.push_back(str.substr(pos1));
    }
    return res;
}

}//namespace Tool
