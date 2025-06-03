#include "telagrafo.h"
#include "ui_telagrafo.h"

telagrafo::telagrafo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::telagrafo)
{
    ui->setupUi(this);
}

telagrafo::~telagrafo()
{
    delete ui;
}
