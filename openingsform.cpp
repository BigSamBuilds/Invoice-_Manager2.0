#include "openingsform.h"
#include "ui_openingsform.h"
#include <QLabel>
#include <QMovie>

OpeningsForm::OpeningsForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OpeningsForm)
{
    ui->setupUi(this);

    QMovie *mv = new QMovie(":images/cubic2.gif");
    ui->giftLabel->setMovie(mv);
    mv->setScaledSize(ui->giftLabel->size());
    ui->giftLabel->movie()->start();
}

OpeningsForm::~OpeningsForm()
{
    delete ui;
}
