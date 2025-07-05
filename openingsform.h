#ifndef OPENINGSFORM_H
#define OPENINGSFORM_H

#include <QWidget>

namespace Ui {
class OpeningsForm;
}

class OpeningsForm : public QWidget
{
    Q_OBJECT

public:
    explicit OpeningsForm(QWidget *parent = nullptr);
    ~OpeningsForm();

private:
    Ui::OpeningsForm *ui;
};

#endif // OPENINGSFORM_H
