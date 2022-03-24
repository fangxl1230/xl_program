#ifndef PROCESSCONTROL_H
#define PROCESSCONTROL_H


class ProcessControl {
public:
    /**
     * @brief 构造函数和析构函数
     */
    ProcessControl();
    ~ProcessControl();

    /**
     * @brief Init
     */
    void Init();
    /**
     * @brief RunLoop
     */
    void RunLoop();

};

#endif // PROCESSCONTROL_H
