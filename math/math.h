#ifndef MATH_H
#define MATH_H
#include <vector>
#include <string>

namespace xl_math {

class Math {
public:
    Math() = delete;


    /**
     * @brief ForwardConvert 10进制转换任意进制
     * @return roman,2,8,10,16,26,32,52,58,64
     */
    std::vector<std::string> ForwardConvert();
    /**
     * @brief InverseConvert 任意进制转10进制
     * @return 10进制
     */
    static int InverseConvert(std::string input, int bit_state);


};

} //namespace Math
#endif // MATH_H
