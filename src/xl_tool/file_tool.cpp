#include "file_tool.h"
#include <fstream>

namespace xl_tool {
/**
 * @brief txt文件读写
 */
std::string FileTool::ReadTxtFile(const std::string& file_path, std::string& error_info){
    if (file_path.empty()) {
        error_info = "file path is empty";
        return "";
    }
    std::ifstream in_file;
    in_file.open(file_path.c_str(), std::ios::in);
    if (!in_file.is_open() || !in_file.good()) {
        error_info = "打开" + file_path + "文件失败";
    }
    std::string file_string = "", line_string = "";
    while (std::getline(in_file, line_string)) {
        file_string += (line_string + "\n");
    }
    in_file.close();
    return file_string;
}
bool FileTool::WriteTxtFile(const std::string& file_path, const std::string& file_string, std::string& error_info){
    if (file_path.empty()) {
        error_info = "file path is empty";
        return "";
    }
    std::ofstream out_file;
    //若文件不存在，不会崩溃，会创建file_path
    out_file.open(file_path.c_str(), std::ios::out /*| std::ios::app 不覆盖源文件*/);
    if (!out_file.is_open() || !out_file.good()) {
        error_info = "打开" + file_path + "文件失败";
        return false;
    }
    out_file << file_string << '\n';
    out_file.close();
    return true;
}

/**
 * @brief xml文件读写
 */
std::string FileTool::ReadXmlFile(const std::string& file_path, std::string &error_info){
    (void)file_path;
    (void)error_info;
    return "";
}
bool FileTool::WriteXmlFile(const std::string& file_path, std::string &error_info){
    (void)file_path;
    (void)error_info;
    return true;
}
/**
 * @brief json文件读写
 */
std::string FileTool::ReadJsonFile(const std::string& file_path, std::string& error_info){
    (void)file_path;
    (void)error_info;
    return "";
}
bool FileTool::WriteJsonFile(const std::string& file_path, std::string& error_info){
    (void)file_path;
    (void)error_info;
    return true;
}

}//namespace Tool
