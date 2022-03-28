#ifndef HEX_CONVERT_H
#define HEX_CONVERT_H

#include <QWidget>

namespace Ui {
class HexConvert;
}

class HexConvert : public QWidget {
    Q_OBJECT

public:
    explicit HexConvert(QWidget *parent = nullptr);
    ~HexConvert();

private:
    Ui::HexConvert *ui;
};

#endif // HEX_CONVERT_H
