#include "tcpsocketthread.h"
#include "global.h"

#include <QHostAddress>

TcpSocketThread::TcpSocketThread(int descriptor, QObject* parent) :
    QThread(parent),
    m_socketDescriptor(descriptor) {}

void TcpSocketThread::onReadyRead()
{
     QString msg(m_socket->readAll());
     qInfo().noquote() << "   └" << msg;

     QSharedPointer<QTextStream> ts(new QTextStream(m_socket.data()));
     *ts << "hello world!\n";

     // start implement your idea here

     m_socket->disconnectFromHost();
}

void TcpSocketThread::onDisconnected()
{
    m_socket->close();
    quit();
}

void TcpSocketThread::run()
{
    m_socket = QSharedPointer<QTcpSocket>(new QTcpSocket);
    m_socket->setSocketDescriptor(m_socketDescriptor);
    connect(m_socket.data(), SIGNAL(readyRead()), this, SLOT(onReadyRead()), Qt::DirectConnection);
    connect(m_socket.data(), SIGNAL(disconnected()), this, SLOT(onDisconnected()), Qt::DirectConnection);
    qInfo().noquote() << "\n->" << m_socket->peerAddress().toString() << global::getCurrentTimeString();
    exec();
}
