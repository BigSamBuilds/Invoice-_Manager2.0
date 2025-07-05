#include "enableforgeingkeysqlite.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>

bool EnableForgeingKeySQLITE::enable(){
    QSqlQuery query(Database::getDatabase());
    if (!query.exec("PRAGMA foreign_keys = ON;")) {
        qDebug() << "Error: could not enable foreign keys - " << query.lastError().text();
        return false;
    } else {
        qDebug() << "Foreign keys enabled";
        return true;
    }
}
