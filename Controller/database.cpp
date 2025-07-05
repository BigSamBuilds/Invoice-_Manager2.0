#include "database.h"
#include "functiontools.h"

#include <QSqlDatabase>
#include <QMessageBox>
#include <QString>

static QSqlDatabase globalDB;

bool Database::initialize(){

    globalDB = QSqlDatabase::addDatabase("QSQLITE");
    globalDB.setDatabaseName("data.db");

    return open();
}


QSqlDatabase& Database::getDatabase(){
    return globalDB;
}

bool Database::open(){
    if (!globalDB.open()) {
        qWarning() << "Failed to open the database:";// << globalDB.lastError().text();
        FunctionTools::messageBox((QString)"DB Connection", (QString)"Failed to open the database", QMessageBox::Critical);
        return false;
    } else {
        qDebug() << "Database opened successfully.";
        return true;
    }
}

bool Database::close(){
    globalDB.close();
    return true;
}
