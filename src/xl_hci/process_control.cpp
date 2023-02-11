#include "process_control.h"

#include "xl_spm/math/matrix.h"
#include "xl_spm/math/mathematical.h"
#include "xl_spm/math/vector3.h"
#include <QString>
#include <iostream>

//#include "LeetCode/leetcode_test.h"
ProcessControl::ProcessControl() {

}

ProcessControl::~ProcessControl() {

}

void ProcessControl::Init() {

}

void ProcessControl::RunLoop() {



    //矩阵验证
    xl_math::Matrix A = xl_math::Matrix("[3,3,0;2,5,-4;-1,1,0]");
    A.Print("A");
    A.Print();



    //算法验证
//    std::vector<double> xdata = {0.5,1.0,1.5,2.0,2.5,3.0};
//    std::vector<double> ydata = {1.75,2.45,3.81,4.80,7.00,8.60};
//    std::vector<double> coefficient;
//    unsigned int pow_n = 2;
//    std::string error_info = "";
//    xl_math::Mathematical::LeastSquare(xdata, ydata, pow_n, coefficient, error_info);
//    xl_math::vectorx coff = xl_math::vectorx(coefficient);
//    coff.Print();

    int aa = 0;



}
