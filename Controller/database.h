#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>
#include <QSqlDatabase>

class Database
{
public:
    static bool initialize();
    static QSqlDatabase& getDatabase();
    static bool open();
    static bool close();

};

#endif // DATABASE_H
