#include "leetcode.h"
#include "ui_leetcode.h"
#include "xl_tool/file_tool.h"
#include "xl_tool/str_tool.h"
#include "pre_define.h"

#include <iostream>
namespace hci {

LeetCode::LeetCode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeetCode) {
    ui->setupUi(this);
}

LeetCode::~LeetCode() {
    delete ui;
}

namespace {
static unsigned int subject_index = 1;
std::vector<std::string> str_source_list = {};
std::string leetcode_user_path = "/user/leetcode.txt";
std::string file_path = source_path + leetcode_user_path;
std::string str_sep = "\n";
std::string str_sep_interval = ";";
std::string str_sep_item = ":";

//LeetCodeData m_leetcode_data = {};     //力扣总数据结构体
/**
 * @brief 单个力扣题目相关数据的结构体
 */
struct SubjectData {
    unsigned int m_index;   //题目索引
    std::string m_subject;  //题目
    std::string m_degree;   //难度系数
    std::string m_describe; //题目描述

    bool is_error = false;
};
std::vector<SubjectData> m_subject_list = {};
unsigned int m_size;
unsigned int m_min;
unsigned int m_max;

std::vector<std::string> GetItemList (const std::string& ItemStr) {
    std::vector<std::string> item_list = xl_tool::StrTool::SplitString(ItemStr, str_sep_item);
    if (item_list.size() != 2 && (item_list[0] != "index" ||
                                  item_list[0] != "subject" ||
                                  item_list[0] != "degree" ||
                                  item_list[0] != "index")) {
        return {};
    }
    return item_list;
}
std::string ConvertToString () {
    std::string test_str = "";
    for (const SubjectData& sub : m_subject_list) {
        test_str += ("index:" + std::to_string(sub.m_index) + ";" +
                     "subject:" + sub.m_subject + ";" +
                     "degree:" + sub.m_degree + ";" +
                     "describe:" + sub.m_describe + ";" + str_sep);
    }
    return test_str;
}

}
void LeetCode::Init() {

    std::string file_string = "";
    std::string error_info = "";
    file_string = xl_tool::FileTool::ReadTxtFile(file_path, error_info);

    str_source_list = xl_tool::StrTool::SplitString(file_string, str_sep);

    ui->source_textEdit->setText(QString::fromStdString(file_string));
    if (str_source_list.size() == 0) {
        return;
    }
    for (const std::string& str : str_source_list) {
        if (str[0] != 'i') {
            continue;
        }
        std::vector<std::string> leetcode_data_list = xl_tool::StrTool::SplitString(str, str_sep_interval);
        SubjectData sbuject_data = {};
        sbuject_data.m_index = std::atoi(GetItemList(leetcode_data_list[0])[1].c_str());
        sbuject_data.m_subject = GetItemList(leetcode_data_list[2])[1];
        sbuject_data.m_degree = GetItemList(leetcode_data_list[1])[1];
        sbuject_data.m_describe = GetItemList(leetcode_data_list[3])[1];
        m_subject_list.push_back(sbuject_data);
    }
    //数据过滤
    Filter();
    //更新UI界面
    UpdateUI();
}


void LeetCode::Filter () {
    //1.排序算法,升序
    for (unsigned int i = 0; i < m_subject_list.size(); i++) {
        for (unsigned int j = i; j < m_subject_list.size(); j++) {
            if (m_subject_list[i].m_index > m_subject_list[j].m_index) {
                SubjectData sub_temp = m_subject_list[i];
                m_subject_list[i] = m_subject_list[j];
                m_subject_list[j] = sub_temp;
            }
        }
    }

    //2.删除重复数据
    std::vector<SubjectData> temp_list = {};
    unsigned int temp_index = m_subject_list[0].m_index;
    for (unsigned int i = 0; i < m_subject_list.size(); i++) {
        if (i == 0) {
            temp_list.push_back(m_subject_list[i]);
            temp_index = m_subject_list[i].m_index;
        }
        if (m_subject_list[i].m_index != temp_index) {
            temp_list.push_back(m_subject_list[i]);
            temp_index = m_subject_list[i].m_index;
        }
    }
    m_subject_list = temp_list;

}

//slots:
void LeetCode::on_index_spinBox_textChanged(const QString &arg1) {
    subject_index = std::atoi(arg1.toStdString().c_str());
    ui->index_spinBox->setValue(subject_index);
    UpdateUI();
}
void LeetCode::on_refresh_pushButton_clicked() {

}
void LeetCode::on_save_pushButton_clicked() {
    //数据过滤
    Filter();
    std::string error_info = "";
    xl_tool::FileTool::WriteTxtFile(file_path, ConvertToString(), error_info);
}

void LeetCode::UpdateData() {



}

void LeetCode::UpdateUI() {
    for (const SubjectData& sub : m_subject_list) {
        if (sub.m_index == subject_index) {
            ui->index_spinBox->setValue(m_subject_list[subject_index-1].m_index);
            ui->degree_lineEdit->setText(QString::fromStdString(m_subject_list[subject_index-1].m_degree));
            ui->subject_lineEdit->setText(QString::fromStdString(m_subject_list[subject_index-1].m_subject));
            ui->describe_textEdit->setText(QString::fromStdString(m_subject_list[subject_index-1].m_describe));
        }
    }
    ui->test_textEdit->setText(QString::fromStdString(ConvertToString()));
}

} // namespace hci





