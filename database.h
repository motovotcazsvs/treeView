#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>


class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    void inserIntoTable(const QVariantList &data);
    void updateRecord(QString, QString, QString);

signals:

public slots:

private:
    QSqlDatabase db;

private:
    void openDataBase();
    void closeDataBase();
    void createTableCountries();
    void createTableOperators();

};

#endif // DATABASE_H
