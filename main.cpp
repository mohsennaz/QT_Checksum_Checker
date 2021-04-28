#include "dialog.h"
#include <QApplication>
#include <QDebug>
#include <QByteArray>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    QByteArray byte;
    const char *s = "2233445566";

    QList<quint8> list;
    list.append(22);
    list.append(33);
    list.append(44);
    list.append(55);
    list.append(66);


    //qDebug() << "The Result of "<< list << " with lenght " << list.size() << " is " <<  qChecksum((char*) list,list.size()) ;


    return a.exec();
}
