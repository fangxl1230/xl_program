/*****************************************************
 * @File matrix.h
 * @Description 矩阵相关
 * @Date 2022年10月2日
 * @Author fxl
 * @Copyright(C), 2022, fxl .
*****************************************************/
#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H
#include <vector>
namespace xl_math {

class Matrix {
public:
    Matrix(){};
    Matrix(unsigned int row, unsigned int column);
//    Matrix (const Matrix& source);
    ~Matrix() {}


    /** *********************
     * 矩阵读写相关接口
     * *********************/
    //获取矩阵的行数
    unsigned int GetRowNumber() {
        return m_row;
    }
    //获取矩阵的列数
    unsigned int GetColumnNumber() {
        return m_column;
    }
    //矩阵的行元素列表，从1开始数
    std::vector<double> GetRowVector(const unsigned int row);
    //矩阵的列元素列表，从1开始数
    std::vector<double> GetColumnVector(const unsigned int column);
    bool SetRowVector(const unsigned int row, const std::vector<double>& row_vector);
    bool SetColumnVector(const unsigned int column, const std::vector<double>& column_vector);

    /**
     * @brief 转置
     */
    Matrix Transpose();
    /**
     * @brief 余子式
     */
    Matrix Cofactor(const unsigned int r, const unsigned int c);
    /**
     * @brief 代数余子式
     */
    double AlgebraicCofactor(const unsigned int r, const unsigned int c);
    /**
     * @brief 伴随矩阵
     */
    Matrix Adjoint();
    /**
     * @brief 方阵的逆矩阵
     */
    Matrix Inverse();
    /**
     * @brief 方阵行列式的值
     */
    double Value();
    /**
     * @brief 重载[],从0开始计数
     */
    std::vector<double> operator[] (unsigned int column);
    /**
     * @brief 重载=
     */
    bool operator= (const Matrix& mat);
    /**
     * @brief 重载+
     */
    bool operator+ (const Matrix& mat);
    /**
     * @brief 重载-
     */
    bool operator- (const Matrix& mat);
    /**
     * @brief 重载* 数乘
     */
    bool operator* (const double k);
    /**
     * @brief 重载/ 数除
     */
    bool operator/ (const double k);
    /**
     * @brief 重载^ 点乘
     */
    Matrix operator^ (const Matrix& mat);
    /**
     * @brief 矩阵打印工具
     */
    void Print();


    std::vector<std::vector<double>> m_matrix;//列表中的每个元素代表这一行
private:

    unsigned int m_row;   //矩阵的行数
    unsigned int m_column;//矩阵的列数

    bool is_square;       //矩阵是一个方阵,是方阵才能有逆矩阵
};
} //namespace xl_math
#endif // MATH_MATRIX_H
