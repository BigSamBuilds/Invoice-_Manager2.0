#include "functiontools.h"


void FunctionTools::messageBox(QString title, QString information, QMessageBox::Icon icon){
    QMessageBox bx;
    bx.setWindowTitle(title);
    bx.setText(information);
    // bx.setInformativeText(globalDB.lastError().text());
    bx.setIcon(icon);
    bx.exec();
}
