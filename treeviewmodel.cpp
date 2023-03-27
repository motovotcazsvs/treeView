#include "treeviewmodel.h"
#include <QStandardItem>

#include <QDebug>


TreeViewModel::TreeViewModel(QObject *parent)
    : QStandardItemModel { parent }
{
/*
    setColumnCount(1);
    QStandardItem *rootItem = invisibleRootItem();
    QStandardItem *group1 = new QStandardItem;
    QStandardItem *group2 = new QStandardItem;
    QStandardItem *value1 = new QStandardItem;
    QStandardItem *value2 = new QStandardItem;
    QStandardItem *value3 = new QStandardItem;
    QStandardItem *value4 = new QStandardItem;
    QStandardItem *value5 = new QStandardItem;
    QStandardItem *value6 = new QStandardItem;
    group1->setText("Grupo 1");
    group2->setText("Grupo 2");
    value1->setText("Valor 1");
    value2->setText("Valor 2");
    value3->setText("Valor 3");
    //value4->setText("Valor 4");
    //value5->setText("Valor 5");
    //value6->setText("Valor 6");
    group1->appendRow(value1);
    group1->appendRow(value2);
    group1->appendRow(value3);
    group2->appendRow(value4);
    group2->appendRow(value5);
    group2->appendRow(value6);
    rootItem->appendRow(group1);
    rootItem->appendRow(group2);
*/
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("system.db");
    if(db.open() == false){
        qDebug() << "error open data base!";
    }

    QStandardItem *standardItem = invisibleRootItem();
    QSqlQuery query(db);
    query.prepare("SELECT name, code, mcc FROM countries ORDER BY name");
    if(query.exec() == false) qDebug() << "data was not loaded from the database!";

    while(query.next()){
        QStandardItem *item_country = new QStandardItem(query.value(0).toString());
        QSqlQuery query2(db);
        query2.prepare("SELECT name, mnc FROM operators WHERE mcc = " + query.value(2).toString());
        if(query2.exec() == false) qDebug() << "data was not loaded from the database!";

        while(query2.next()){
            QStandardItem *item_operator = new QStandardItem(query2.value(0).toString() + " (" + query.value(2).toString() + ", " + query2.value(1).toString() + ")");
            item_country->appendRow(item_operator);
        }

        QImage image("AD.png");
        QStandardItem *item = new QStandardItem();
        item->setData(QVariant(QPixmap::fromImage(image)));
        item_country->appendRow(item);
        standardItem->appendRow(item_country);
    }







}

