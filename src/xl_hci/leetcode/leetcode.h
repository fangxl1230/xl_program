#ifndef HCI_LEETCODE_LEETCODE_H
#define HCI_LEETCODE_LEETCODE_H
#include <QWidget>
namespace hci {
namespace Ui {
class LeetCode;
}

class LeetCode : public QWidget {
    Q_OBJECT

public:
    explicit LeetCode(QWidget *parent = nullptr);
    ~LeetCode();
    void Init();
private slots:


    void on_index_spinBox_textChanged(const QString &arg1);

    //将leetcode的题目刷新到index最小的那个
    void on_refresh_pushButton_clicked();
    //将当前列表存到文件中
    void on_save_pushButton_clicked();

private:

    void UpdateData();
    /**
     * @brief 更新界面信息
     */
    void UpdateUI();
    /* 过滤器
     * 1、检测数据是否有重复的，有相同的索引则删除后面的；
     * 2、对数据进行排序，让数据变成从小到大的顺序
     * 3、若数据有变化，则将更新后的写到文件中；
     */
    void Filter();

    Ui::LeetCode *ui;

};
} // namespace hci
#endif // HCI_LEETCODE_LEETCODE_H
