#include "hex_convert.h"
#include "ui_hex_convert.h"

HexConvert::HexConvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HexConvert) {
    ui->setupUi(this);
}

HexConvert::~HexConvert() {
    delete ui;
}
