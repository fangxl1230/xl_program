#ifndef HCI_HEX_CONVERT_H
#define HCI_HEX_CONVERT_H
#include <QWidget>

namespace hci {
namespace Ui {
class HexConvert;
}
class HexConvert : public QWidget {
    Q_OBJECT
public:
    explicit HexConvert(QWidget *parent = nullptr);
    ~HexConvert();
private slots:
    void on_cancel_button_clicked();
    void on_hex_convert_button_clicked(); 
    void on_clear_button_clicked();

    //checked����
    void on_roman_checkBox_clicked();
    void on_binary_checkBox_clicked();
    void on_octal_checkBox_clicked();
    void on_hex10_checkBox_clicked();
    void on_hex16_checkBox_clicked();
    void on_hex32_checkBox_clicked();
    void on_hex64_checkBox_clicked();
    void on_spinBox_textChanged(const QString &arg1);

private:
    /**
     * @brief ��ʼ��
     */
    void Init();
    /**
     * @brief ForwardConvert 10����ת���������
     * @return roman,2,8,10,16,26,32,52,58,64
     */
    std::vector<std::string> ForwardConvert();
    /**
     * @brief InverseConvert �������ת10����
     * @return 10����
     */
    int InverseConvert();
    /**
     * @brief Clear ������а�ť���ı���״̬
     */
    void ClearEdit();
    void UpdateCheckBoxState();
    void UpdateSpinBoxState();
    void UpdateExplainTextEditState();

    Ui::HexConvert *ui;
};

} // namespace hci
#endif // HCI_HEX_CONVERT_H
