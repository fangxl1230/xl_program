#include "hex_convert.h"
#include "ui_hex_convert.h"
#include <cmath>
#include <iostream>
namespace hci {
namespace {
const QString explain_init = "";
const QString explain_roman = "{1000,  M}\n{900,  CM}\n{500,   D}\n{400,  CD}\n{100,   C}\n{90,   XC}\n{50,    L}\n{40,   XL}\n{10,    X}\t\n{9,    IX}\t\n{5,     V}\t\n{4,    IV}\t\n{1,     I}";
}
HexConvert::HexConvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HexConvert) {
    ui->setupUi(this);
    Init();
}

HexConvert::~HexConvert() {
    delete ui;
}

//页面初始化
void HexConvert::Init() {
    UpdateCheckBoxState();
    ui->hex10_checkBox->setCheckState(Qt::Checked);
    ui->spinBox->setValue(10);
    ui->result_roman_linedit->cursor();
    ui->spinBox->setSuffix("hex");
    ClearEdit();
}

void HexConvert::on_hex_convert_button_clicked() {
    std::vector<std::string> result_list = ForwardConvert();
    ui->result_roman_linedit->setText(QString::fromStdString(result_list[0]));
    ui->result_2_linedit->setText(QString::fromStdString(result_list[1]));
    ui->result_8_linedit->setText(QString::fromStdString(result_list[2]));
    ui->result_10_linedit->setText(QString::fromStdString(result_list[3]));
    ui->result_16_linedit->setText(QString::fromStdString(result_list[4]));
}

void HexConvert::on_cancel_button_clicked() {
    this->close();
}

void HexConvert::on_clear_button_clicked() {
    Init();
}

namespace {
static int bit_state = 10;
const std::pair<int, std::string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

//十进制转换成其他进制
std::string IntToRoman(int intx) {
    std::string roman = "";
    for (const auto&[value, symbol] : valueSymbols) {
        while (intx >= value) {
            intx -= value;
            roman += symbol;
        }
        if (intx == 0) {
            break;
        }
    }
    return roman;
}
std::string IntToBinary(int intx) {
    std::string binary = "";
    int temp = intx / 2;
    int left = intx % 2;
    if (temp > 0) {
        binary += IntToBinary(temp);
    }
    if (left < 2 ) {
        binary += (left + '0');
    }
    else {
        binary += (left - 2);
    }
    return binary;
}
std::string IntToOctal(int intx) {
    std::string octal = "";
    int temp = intx / 8;
    int left = intx % 8;
    if (temp > 0) {
        octal += IntToOctal(temp);
    }
    if (left < 8 ) {
        octal += (left + '0');
    }
    else {
        octal += (left - 8);
    }
    return octal;
}
std::string IntToHex(int intx) {
    std::string hexadecimal = "";
    int temp = intx / 16;
    int left = intx % 16;
    if (temp > 0) {
        hexadecimal += IntToHex(temp);
    }
    if (left < 10 ) {
        hexadecimal += (left + '0');
    }
    else {
        hexadecimal += ('A' + left - 10);
    }
    return hexadecimal;
}
//std::string IntTo26(int intx);
//std::string IntTo32(int intx);
//std::string IntTo52(int intx);
//std::string IntTo58(int intx);
//其他进制转换成十进制
int IntFromRoman(std::string str) {
    int count = 0;
    std::map<char, int> roma = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
    unsigned num = str.size();
    for (unsigned i = 0; i < num; i++) {
        int a = roma[str[i]];
        int b = roma[str[i+1]];
        if ((i < num - 1) && (a < b)) {
            count += (b - a);
            i++;
        }
        else {
            count += a;
        }
    }
    return count;
}
}
int HexConvert::InverseConvert() {
    int output = 0;
    if (bit_state == 0) {
        output = IntFromRoman(ui->input_linedit->text().toStdString());
    }
    else {
        std::string str = ui->input_linedit->text().toStdString();
        int num = (int)str.size() - 1;
        for (unsigned i = 0; i < str.size(); i++) {
            output += ((str[i] - 48) * std::pow(bit_state, num));
            num--;
        }
    }
    return output;
}
std::vector<std::string> HexConvert::ForwardConvert() {
    std::vector<std::string> result(10, "");
    //input为10进制数，所有输入全转换成10进制数
    int input = InverseConvert();
    result[0] = IntToRoman(input);
    result[1] = IntToBinary(input);
    result[2] = IntToOctal(input);
    result[3] = std::to_string(input);
    result[4] = IntToHex(input);
    return result;
}

void HexConvert::ClearEdit() {
    ui->input_linedit->clear();
    ui->result_roman_linedit->clear();
    ui->result_2_linedit->clear();
    ui->result_8_linedit->clear();
    ui->result_10_linedit->clear();
    ui->result_16_linedit->clear();
    ui->result_26_linedit->clear();
    ui->result_32_linedit->clear();
    ui->result_52_linedit->clear();
    ui->result_58_linedit->clear();
    ui->result_64_linedit->clear();
}

void HexConvert::UpdateCheckBoxState() {
    ui->roman_checkBox->setCheckState(Qt::Unchecked);
    ui->binary_checkBox->setCheckState(Qt::Unchecked);
    ui->octal_checkBox->setCheckState(Qt::Unchecked);
    ui->hex10_checkBox->setCheckState(Qt::Unchecked);
    ui->hex16_checkBox->setCheckState(Qt::Unchecked);
    ui->hex32_checkBox->setCheckState(Qt::Unchecked);
    ui->hex64_checkBox->setCheckState(Qt::Unchecked);
    UpdateExplainTextEditState();
}

void HexConvert::UpdateSpinBoxState() {
    if (bit_state == 0) {
        ui->roman_checkBox->setCheckState(Qt::Checked);
    }
    else if (bit_state == 2) {
        ui->binary_checkBox->setCheckState(Qt::Checked);
    }
    else if (bit_state == 8) {
        ui->octal_checkBox->setCheckState(Qt::Checked);
    }
    else if (bit_state == 10) {
        ui->hex10_checkBox->setCheckState(Qt::Checked);
    }
    else if (bit_state == 16) {
        ui->hex16_checkBox->setCheckState(Qt::Checked);
    }
    else if (bit_state == 32) {
        ui->hex32_checkBox->setCheckState(Qt::Checked);
    }
    else if (bit_state == 64) {
        ui->hex64_checkBox->setCheckState(Qt::Checked);
    }
    else {
        UpdateCheckBoxState();
    }
    UpdateExplainTextEditState();
}
void HexConvert::UpdateExplainTextEditState() {
    if (bit_state == 0) {
        ui->explain_txetedit->setText(explain_roman);
    }
    else {

        ui->explain_txetedit->setText(QString::fromStdString(std::to_string(bit_state)));
    }
}

void HexConvert::on_roman_checkBox_clicked() {
    if (ui->roman_checkBox->isChecked()) {
        UpdateCheckBoxState();
        ui->spinBox->setValue(0);
        ui->roman_checkBox->setCheckState(Qt::Checked);
        bit_state = 0;
        ui->spinBox->setValue(bit_state);
    }
    else {
        std::cout << "roman_checkBox == 4" << std::endl;
    }
}

void HexConvert::on_binary_checkBox_clicked() {
    if (ui->binary_checkBox->isChecked()) {
        UpdateCheckBoxState();
        ui->spinBox->setValue(0);
        ui->binary_checkBox->setCheckState(Qt::Checked);
        bit_state = 2;
        ui->spinBox->setValue(bit_state);
    }
    else {
        std::cout << "binary_checkBox == 4" << std::endl;
    }
}
void HexConvert::on_octal_checkBox_clicked() {
    if (ui->octal_checkBox->isChecked()) {
        UpdateCheckBoxState();
        ui->spinBox->setValue(0);
        ui->octal_checkBox->setCheckState(Qt::Checked);
        bit_state = 8;
        ui->spinBox->setValue(bit_state);
    }
    else {
        std::cout << "octal_checkBox == 4" << std::endl;
    }
}

void HexConvert::on_hex10_checkBox_clicked() {
    if (ui->hex10_checkBox->isChecked()) {
        UpdateCheckBoxState();
        ui->spinBox->setValue(0);
        ui->hex10_checkBox->setCheckState(Qt::Checked);
        bit_state = 10;
        ui->spinBox->setValue(bit_state);
    }
    else {
        std::cout << "hex10_checkBox == 4" << std::endl;
    }
}

void HexConvert::on_hex16_checkBox_clicked() {
    if (ui->hex16_checkBox->isChecked()) {
        UpdateCheckBoxState();
        ui->spinBox->setValue(0);
        ui->hex16_checkBox->setCheckState(Qt::Checked);
        bit_state = 16;
        ui->spinBox->setValue(bit_state);
    }
    else {
        std::cout << "hex16_checkBox == 4" << std::endl;
    }
}

void HexConvert::on_hex32_checkBox_clicked() {
    if (ui->hex32_checkBox->isChecked()) {
        UpdateCheckBoxState();
        ui->spinBox->setValue(0);
        ui->hex32_checkBox->setCheckState(Qt::Checked);
        bit_state = 32;
        ui->spinBox->setValue(bit_state);
    }
    else {
        std::cout << "hex32_checkBox == 4" << std::endl;
    }
}

void HexConvert::on_hex64_checkBox_clicked() {
    if (ui->hex64_checkBox->isChecked()) {
        UpdateCheckBoxState();
        ui->spinBox->setValue(0);
        ui->hex64_checkBox->setCheckState(Qt::Checked);
        bit_state = 64;
        ui->spinBox->setValue(bit_state);
    }
    else {
        std::cout << "hex64_checkBox == 4" << std::endl;
    }
}

void HexConvert::on_spinBox_textChanged(const QString &arg1) {
    bit_state = std::atoi(arg1.toStdString().c_str());
    ui->spinBox->setValue(bit_state);
    UpdateSpinBoxState();
}

} // namespace hci
