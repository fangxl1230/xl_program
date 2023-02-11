/*****************************************************
 * @File vector3.h
 * @Description 一维数组为3的相关计算
 * @Date 2022年11月27日
 * @Author fxl
 * @Copyright(C), 2022, fxl . std
*****************************************************/
#ifndef MATH_VECTOR3_H
#define MATH_VECTOR3_H
#include <vector>
#ifdef DEBUG_TEST
#include <iostream>
#endif
namespace xl_math {
class vectorx {
public:
    vectorx () {}
    vectorx (std::vector<double> vector) : m_vector(vector){}
    ~vectorx () {}

    void Set(std::vector<double> vector) {
        m_vector = vector;
    }
#ifdef DEBUG_TEST
    void Print() {
        std::cout << "[";
        for (unsigned int i = 0; i < m_vector.size(); i++) {
            std::cout << m_vector[i];
            std::cout << ((i < m_vector.size() - 1) ? "\t" : "");
        }
        std::cout << "]" << std::endl;
    }
#endif
private:
    std::vector<double> m_vector;
};

class vector3 {
public:
    vector3() : x(0.0), y(0.0), z(0.0) {}
    vector3(double x, double y, double z) : x(x), y(y), z(z) {}

    vector3(const vector3& source) {
        x = source.x;
        y = source.y;
        z = source.z;
    }

    /**
     * @brief 重载=
     */
    bool operator= (const vector3& vec) {
        return ((vec.x == x) && (vec.y == y) && (vec.z == z));
    }
    /**
     * @brief 重载+
     */
    vector3 operator+ (const vector3& vec) {
        return vector3(x + vec.x, y + vec.y, z + vec.z);
    }
    /**
     * @brief 重载+=
     */
    void operator+= (const vector3& vec) {
        x += vec.x;
        y += vec.y;
        z += vec.z;;
    }
    /**
     * @brief 重载-
     */
    vector3 operator- (const vector3& vec) {
        return vector3((x - vec.x), (y - vec.y), (z - vec.z));
    }
    /**
     * @brief 重载-=
     */
    void operator-= (const vector3& vec) {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;;
    }
    /**
     * @brief 重载* 数乘
     */
    vector3 operator* (const double k) {
        return vector3((x * k), (y * k), (z * k));
    }
    /**
     * @brief 重载/ 数乘
     */
    vector3 operator/ (const double k) {
        return vector3((x / k), (y / k), (z / k));
    }
    /**
     * @brief 重载^ 点乘 (3*1) ^ (1*3) = (1*1)
     */
    double operator^ (const vector3& vec) {
        return (x * vec.x) + (y * vec.y) + (z* vec.z);
    }

#ifdef DEBUG_TEST
    /**
     * @brief vector3打印工具
     */
    void Print() {
        std::cout << "[" << x <<"," << y << "," << z << "]" << std::endl;
    }
#endif

    double x;
    double y;
    double z;
};
} //namespace xl_math
#endif // MATH_VECTOR3_H
