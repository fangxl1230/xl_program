#ifndef XL_TOOL_FILETOOL_H
#define XL_TOOL_FILETOOL_H
#include <string>
namespace xl_tool {
class FileTool {
public:
    FileTool() = delete;

    /**
     * @brief txt文件读写
     */
    static std::string ReadTxtFile(const std::string& file_path, std::string& error_info);
    static bool WriteTxtFile(const std::string& file_path, const std::string& file_string, std::string& error_info);
    /**
     * @brief xml文件读写
     */
    static std::string ReadXmlFile(const std::string& file_path, std::string& error_info);
    static bool WriteXmlFile(const std::string& file_path, std::string& error_info);
    /**
     * @brief json文件读写
     */
    static std::string ReadJsonFile(const std::string& file_path, std::string& error_info);
    static bool WriteJsonFile(const std::string& file_path, std::string& error_info);
};
}//namespace Tool
#endif // XL_TOOL_FILETOOL_H
