#ifndef MATH_H
#define MATH_H
#include <vector>
#include <string>

namespace xl_math {

class Math {
public:
    Math() = delete;


    /**
     * @brief ForwardConvert 10����ת���������
     * @return roman,2,8,10,16,26,32,52,58,64
     */
    std::vector<std::string> ForwardConvert();
    /**
     * @brief InverseConvert �������ת10����
     * @return 10����
     */
    static int InverseConvert(std::string input, int bit_state);


};

} //namespace Math
#endif // MATH_H
