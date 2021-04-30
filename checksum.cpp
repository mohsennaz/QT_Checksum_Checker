#include "checksum.h"
#include <QtDebug>

checksum::checksum(QObject *parent) : QObject(parent)
{

}

quint16 checksum::CRC16Modbus(QStringList list, int lenght)
{
    const quint16 generator = 0xA001;
    quint16 crc = 0xFFFF;

    foreach(QString v, list)
    {
        if(v == "")
        {
            break;
        }
        else
        {
            bool ok;
            crc ^= v.toInt(&ok,16);

            for(int b = 0; b < 8; ++b)
            {
                if((crc & 1) != 0)
                {
                    crc >>= 1;
                    crc ^= generator;
                }
                else
                    crc >>= 1;

            }

        }
    }

    qDebug() << "The CRC result is " << crc;

    return crc;

}
