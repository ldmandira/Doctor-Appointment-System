#include "dbcon.h"
#include <QSqlQuery>
#include <QSqlError>

dbcon::dbcon(const QString &server,
             const QString &driver,
             const QString &databaseName,
             bool trustedConnection)
{
    mDatabase = QSqlDatabase::addDatabase("QODBC");
    mDatabaseName = databaseName;
    mServer = server;
    mDriver = driver;
    mTrustedConnection = trustedConnection;
}


bool dbcon::openDatabase(QString *error){
    mDatabase.setDatabaseName(QString("DRIVER={%1};SERVER=%2;DATABASE=%3;Trusted_Connection=%4")
                              .arg(mDriver)
                              .arg(mServer)
                              .arg(mDatabase)
                              .arg(mTrustedConnection ? "Yes":"No"));
    if(!mDatabase.open()){
        if(error != nullptr){
            *error = mDatabase.lastError().text();
        }
        return false;
    }
    return true;
}
