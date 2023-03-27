#include "database.h"

#include <QFile>
#include <QDebug>

DataBase::DataBase(QObject *parent) : QObject(parent)
{
    //Подключаемся к базе данных
    this->openDataBase();

}

void DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("system.db");
    if(db.open() == false){
        qDebug() << "error open data base!";
    }
}

void DataBase::closeDataBase()
{
    db.close();
}

void DataBase::createTableCountries()
{

}

void DataBase::createTableOperators()
{

}

void DataBase::inserIntoTable(const QVariantList &data)
{
    /* Запрос SQL формируется из QVariantList,
     * в который передаются данные для вставки в таблицу.
     * */
    QSqlQuery query;
    /* В начале SQL запрос формируется с ключами,
     * которые потом связываются методом bindValue
     * для подстановки данных из QVariantList
     * */
    query.prepare("INSERT INTO operators (mcc, mnc, name) VALUES (:mcc, :mnc, :name);");
    query.bindValue(":mcc", data[0].toString());
    query.bindValue(":mnc", data[1].toString());
    query.bindValue(":name", data[2].toString());

    // После чего выполняется запросом методом exec()
    if(query.exec() == false){
        qDebug() << "error insert!";
        qDebug() << query.lastError().text();
    }

}

void DataBase::updateRecord(QString mcc, QString mnc, QString name_operator)
{
    QSqlQuery query;
    query.setForwardOnly(true);
    QString str_query = "UPDATE operators SET name =  " + name_operator + " WHERE mcc = " + mcc + " , mnc = " + mnc + ";";
    query.prepare(str_query);

    if(query.exec() == false){
        qDebug() << "error update!";
        qDebug() << query.lastError().text();
    }

}
