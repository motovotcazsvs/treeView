#ifndef TREEVIEWMODEL_H
#define TREEVIEWMODEL_H
#include <QStandardItemModel>

#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

class TreeViewModel : public QStandardItemModel
{
    Q_OBJECT
public:
    TreeViewModel(QObject *parent = 0);
    QSqlDatabase db;

};

#endif // TREEVIEWMODEL_H
