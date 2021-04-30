#ifndef CHECKSUM_H
#define CHECKSUM_H

#include <QObject>


class checksum : public QObject
{
    Q_OBJECT
public:
    explicit checksum(QObject *parent = nullptr);

    //unsigned long int CRC16_modbus(array*, )

signals:

public slots:
};

#endif // CHECKSUM_H
