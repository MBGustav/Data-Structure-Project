#include "questionario.h"
#include "ui_questionario.h"

Questionario::Questionario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Questionario)
{
    ui->setupUi(this);
}

Questionario::~Questionario()
{
    delete ui;
}
