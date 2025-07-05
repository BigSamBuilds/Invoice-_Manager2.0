#ifndef FUNCTIONTOOLS_H
#define FUNCTIONTOOLS_H

#include <QWidget>
#include <QMessageBox>

class FunctionTools
{
public:
    static void messageBox(QString title, QString information, QMessageBox::Icon icon);
};

#endif // FUNCTIONTOOLS_H
