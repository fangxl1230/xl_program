#ifndef VECTOR3_H
#define VECTOR3_H
#include <vector>
#include <iostream>
namespace xl_math {
class vectorx {
public:
    vectorx () {}
    vectorx (std::vector<double> vector) : m_vector(vector){}
    ~vectorx () {}

    void Set(std::vector<double> vector) {
        m_vector = vector;
    }

    void Print() {
        std::cout << "[";
        for (unsigned int i = 0; i < m_vector.size(); i++) {
            std::cout << m_vector[i];
            std::cout << ((i < m_vector.size() - 1) ? "\t" : "");
        }
        std::cout << "]" << std::endl;
    }
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

    //加法
    double operator+ (const vector3& vec) {
        return (x + vec.x) + (y + vec.y) + (z + vec.z);
    }
    //减法
    double operator- (const vector3& vec) {
        return (x - vec.x) + (y - vec.y) + (z - vec.z);
    }
    //数乘(1×3) * (3×1) = (1×1)
    double operator* (const vector3& vec) {
        return (x * vec.x) + (y * vec.y) + (z * vec.z);
    }
    //数乘(3×1) ^ (1×3) = (1×1)
    double operator^ (const vector3& vec) {
        return (x + vec.x) + (y + vec.y) + (z + vec.z);
    }

    double x;
    double y;
    double z;
};
} //namespace xl_math
#endif // VECTOR3_H
