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
    void on_hex_convert_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::HexConvert *ui;
};

} // namespace hci
#endif // HCI_HEX_CONVERT_H
