// acetone at i2pmail.org

#include "connectionacceptor.h"

#include <QCoreApplication>
#include <QDebug>

const QString VERSION("0.0.1");

int main(int argc, char *argv[])
{
    if (argc < 3) {
        qInfo().noquote() << "Usage: <address> <port>";
        return 1;
    }
    QCoreApplication a(argc, argv);

    qInfo().noquote() << "Qt async server template" << VERSION << "\n";

    QString address(argv[1]);
    quint32 port(QString(argv[2]).toInt());

    ConnectionAcceptor* acceptor = new ConnectionAcceptor(address, port);

    return a.exec();
}
