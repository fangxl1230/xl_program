#include "process_control.h"
#include "LeetCode/leetcode_test.h"
#include <QString>


ProcessControl::ProcessControl() {

}

ProcessControl::~ProcessControl() {

}

void ProcessControl::Init() {

}

void ProcessControl::RunLoop() {
//    LeetCodeTest::Test();


    QString qstr = "12";
    std::string s = qstr.toStdString();
    QString qs = QString::fromStdString(s);
}
