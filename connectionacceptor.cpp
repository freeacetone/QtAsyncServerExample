#include "connectionacceptor.h"
#include "tcpsocketthread.h"
#include "global.h"

#include <QDebug>
#include <QTcpSocket>

ConnectionAcceptor::ConnectionAcceptor(const QString& address, const quint16 port, QObject* parent) :
    QTcpServer(parent)
{
    if (listen(QHostAddress(address), port)) {
        qInfo().noquote() << "<-" << serverAddress().toString() + " : " +
                   QString::number(serverPort()) << global::getCurrentTimeString();
    } else {
        throw std::runtime_error("Server not binded");
    }
}

void ConnectionAcceptor::incomingConnection(qintptr handle)
{
    TcpSocketThread* thread = new TcpSocketThread(handle, this);
    connect (thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
