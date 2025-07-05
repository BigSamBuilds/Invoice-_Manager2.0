#ifndef BUCKUPFORM_H
#define BUCKUPFORM_H

#include <QWidget>

namespace Ui {
class BuckupForm;
}

class BuckupForm : public QWidget
{
    Q_OBJECT

public:
    explicit BuckupForm(QWidget *parent = nullptr);
    ~BuckupForm();

private:
    Ui::BuckupForm *ui;
};

#endif // BUCKUPFORM_H
