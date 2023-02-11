/*****************************************************
 * @File math.h
 * @Description 有关数学的相关算法
 * @Date 2022年09月29日
 * @Author fxl
 * @Copyright(C), 2022, fxl .
*****************************************************/
#ifndef MATH_MATHEMATIVAL_H
#define MATH_MATHEMATIVAL_H

#include <vector>
#include <string>

namespace xl_math {
class Mathematical {
public:
    Mathematical() = delete;
    /**
     * @brief 最小二乘法
     * @param xdata x数组
     * @param ydata y数组
     * @param pown  多项式最高次幂
     * @param error_info 错误信息
     *
     * @return true成功
     * ***********************************************
     * @author fxl
     * @date   2022年10月1日
     * ***********************************************/
    static bool LeastSquare(const std::vector<double>& xdata,
                            const std::vector<double>& ydata,
                            unsigned int pow_n,
                            std::vector<double>& coefficient,
                            std::string& error_info);


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
} //namespace xl_math
#endif // MATH_MATHEMATIVAL_H
