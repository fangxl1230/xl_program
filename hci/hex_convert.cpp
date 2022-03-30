#include "hex_convert.h"
#include "ui_hex_convert.h"
#include "LeetCode/leetcode_001-020.h"
namespace hci {
HexConvert::HexConvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HexConvert) {
    ui->setupUi(this);
}

HexConvert::~HexConvert() {
    delete ui;
}

void HexConvert::on_hex_convert_button_clicked() {
    int input = ui->input_linedit->text().toInt();
    std::string roman = xl_leetcode::LeetCode_001_020::intToRoman(input);

    ui->roman_result_linedit->setText(QString::fromStdString(roman));
}

void hci::HexConvert::on_cancel_button_clicked() {
    this->close();
}


} // namespace hci

