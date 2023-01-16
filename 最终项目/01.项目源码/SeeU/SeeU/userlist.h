#ifndef USERLIST_H
#define USERLIST_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

//静态函数创建与数据库的连接 创建User和friends两个表
static bool CreateConnection()
{
    //创建一个SQLITE数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../UserList.db");

    //打不开
    if(false == db.open()){
        QMessageBox::critical(0,"Cannot open SeeUUserList.db","Unable to establish a database connection.",QMessageBox::Cancel);
        return false;
    }

    //指定连接
    QSqlQuery query(db);

    //创建用户表，主键是账号
    query.exec("create table User("
               "account varchar(20) primary key,"
               "name varchar(20) not null,"
               "password varchar(20) not null,"
               "sign varchar(20),"
               "headImage varchar(10),"
               "state bit default 0)");

   //先插入预定的四个用户
    query.exec("insert into User values('12345','User1','123','I am the first user','head1.png',0)");
    query.exec("insert into User values('23456','User2','123','I am the second user','head2.png',0)");
    query.exec("insert into User values('34567','User3','123','I am the third user','head3.png',0)");
    query.exec("insert into User values('45678','User4','123','I am the fourth user','head.png',0)");

    //创建好友表，主键是id_1和id_2的联合主键
    query.exec("create table friends(id_1 varchar(255) primary key not null,id_2 varchar(255) primary key not null)");

    return true;
}

#endif // USERLIST_H
