/*****************************************************
 * @File math.h
 * @Description �й���ѧ������㷨
 * @Date 2022��09��29��
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
     * @brief ��С���˷�
     * @param xdata x����
     * @param ydata y����
     * @param pown  ����ʽ��ߴ���
     * @param error_info ������Ϣ
     *
     * @return true�ɹ�
     * ***********************************************
     * @author fxl
     * @date   2022��10��1��
     * ***********************************************/
    static bool LeastSquare(const std::vector<double>& xdata,
                            const std::vector<double>& ydata,
                            unsigned int pow_n,
                            std::vector<double>& coefficient,
                            std::string& error_info);


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
} //namespace xl_math
#endif // MATH_MATHEMATIVAL_H
