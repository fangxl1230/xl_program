#include "process_control.h"
#include "LeetCode/leetcode_test.h"
#include "math/mathematical.h"
#include "math/vector3.h"
#include <QString>
#include <iostream>


ProcessControl::ProcessControl() {

}

ProcessControl::~ProcessControl() {

}

void ProcessControl::Init() {

}

void ProcessControl::RunLoop() {
    std::vector<double> xdata = {0.5,1.0,1.5,2.0,2.5,3.0};
    std::vector<double> ydata = {1.75,2.45,3.81,4.80,7.00,8.60};
    std::vector<double> coefficient;
    unsigned int pow_n = 2;
    std::string error_info = "";
    xl_math::Mathematical::LeastSquare(xdata, ydata, pow_n, coefficient, error_info);
    xl_math::vectorx coff = xl_math::vectorx(coefficient);
    coff.Print();

    int aa = 0;


//    LeetCodeTest::Test();
//    LeetCodeTest::Test2();

    QString qstr = "12";
    std::string s = qstr.toStdString();
    QString qs = QString::fromStdString(s);

//    int a = 0x02;
//    int *p = &a;
//    p = 0x01;

//    int* p = (int*)0x00403000;
//    *p = 0x02;

//    std::cout << "p" << p << "  *p" << *p << std::endl;
    int n = 0;
    while (n++ <= 2);
    printf("%d\n", n);



}
