#include "mathematical.h"
#include "matrix.h"
#include "vector3.h"
#include <math.h>
#include <iostream>
namespace xl_math {

/* 最小二乘法
 * AW=B
 */
bool Mathematical::LeastSquare(const std::vector<double>& xdata,
                 const std::vector<double>& ydata,
                 unsigned int pow_n,
                 std::vector<double>& coefficient,
                 std::string& error_info) {

    if ((xdata.size() != ydata.size())) {
        error_info = "xdata" + std::to_string(xdata.size()) + "与ydata" + std::to_string(ydata.size())+ "数据长度不一致";
        return false;
    }
    else if (pow_n < 1) {
        error_info = "pow_n次幂不能低于1";
        return false;
    }
    try {
//        //创建矩阵A1
////        std::vector<double> a11 = { 1.0,  2.0,  -4.0};
////        std::vector<double> a12 = {-2.0,  2.0,   1.0};
////        std::vector<double> a13 = {-3.0,  4.0,  -2.0};
////        std::vector<double> a11 = { 0.0,  3.0,  1.0};
////        std::vector<double> a12 = { 1.0, -1.0,  1.0};
////        std::vector<double> a13 = { 3.0, -1.0,  2.0};
//        std::vector<double> a11 = { 1.0,  2.0,  3.0};
//        std::vector<double> a12 = { 2.0,  2.0,  1.0};
//        std::vector<double> a13 = { 3.0,  4.0,  3.0};
//        Matrix A1 = Matrix(3, 3);
//        A1.SetRowVector(1, a11);
//        A1.SetRowVector(2, a12);
//        A1.SetRowVector(3, a13);

//        std::cout << "--- A1 ---" << std::endl;
//        A1.Print();

//        std::cout << "--- A1.Adjoint ---" << std::endl;
////        A1.Adjoint().Print();
//        A1.Inverse().Print();


//        std::vector<double> a11 = { 5.0,  3.0,  6.0, 0.0};
//        std::vector<double> a12 = { 2.0,  8.0,  0.0, 1.0};
//        std::vector<double> a13 = { 4.0,  2.0,  4.0, 6.0};
//        Matrix A1 = Matrix(4, 3);
//        A1.SetColumnVector(1, a11);
//        A1.SetColumnVector(2, a12);
//        A1.SetColumnVector(3, a13);
//        std::cout << "--- A1 ---" << std::endl;
//        A1.Print();

//        std::vector<double> a21 = { 2.0,  1.0,  3.0};
//        std::vector<double> a22 = { 4.0,  3.0,  2.0};
//        Matrix A2 = Matrix(3, 2);
//        A2.SetColumnVector(1, a21);
//        A2.SetColumnVector(2, a22);
//        std::cout << "--- A2 ---" << std::endl;
//        A2.Print();

//        Matrix A3 = A1*A2;
//        std::cout << "--- A3 ---" << std::endl;
//        A3.Print();

//        std::cout << "--- AT ---" << std::endl;
//        A3.Transpose().Print();

//        std::cout << "__________________________________" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }

    //创建矩阵A
    unsigned int a_row = xdata.size(), a_column = pow_n + 1;
    Matrix A = Matrix(a_row, a_column);
    for (unsigned int j = 0, n = pow_n; j < a_column; n--, j++) {
        std::vector<double> a(a_row);
        for (unsigned int i = 0; i < a_row; i++) {
            a[i] = pow(xdata[i], n);
        }
        A.SetColumnVector(j+1, a);
    }
    std::cout << "--- A ---" << std::endl;
    A.Print();

    //创建矩阵B
    unsigned int b_row = ydata.size(), b_column = 1;
    Matrix B = Matrix(b_row, b_column);
    std::vector<double> b(b_row);
    for (unsigned int i = 0; i < a_row; i++) {
        b[i] = ydata[i];
    }
    B.SetColumnVector(1, b);
    std::cout << "--- B ---" << std::endl;
    B.Print();

    Matrix AT = A.Transpose();
    std::cout << "--- AT ---" << std::endl;
    AT.Print();

    //创建矩阵W
    Matrix W1 = (AT ^ A).Inverse() ^ AT ^ B;
    W1.Print();

    coefficient.resize(W1.GetRowNumber());
    for (unsigned int i = 0; i < W1.GetRowNumber(); i++) {
        coefficient[i] = W1.m_matrix[i][0];
    }
    return true;
}

//int Math::InverseConvert(std::string input, int bit_state) {
//    int output = 0;
//    if (bit_state == 0) {
//        output = IntFromRoman(ui->input_linedit->text().toStdString());
//    }
//    else {
//        std::string str = ui->input_linedit->text().toStdString();
//        int num = (int)str.size() - 1;
//        for (unsigned i = 0; i < str.size(); i++) {
//            output += ((str[i] - 48) * std::pow(bit_state, num));
//            num--;
//        }
//    }
//    return output;
//}


} //namespace xl_math
