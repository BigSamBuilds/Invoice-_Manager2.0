#include "buckupform.h"
#include "ui_buckupform.h"

BuckupForm::BuckupForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BuckupForm)
{
    ui->setupUi(this);
}

BuckupForm::~BuckupForm()
{
    delete ui;
}
