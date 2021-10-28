#ifndef TCPSOCKETTHREAD_H
#define TCPSOCKETTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class TcpSocketThread : public QThread
{
    Q_OBJECT
public:
    TcpSocketThread(int descriptor, QObject* parent = nullptr);

private:
    int m_socketDescriptor;
    QSharedPointer<QTcpSocket> m_socket;

public slots:
    void onReadyRead();
    void onDisconnected();

    // QThread interface
protected:
    void run();
};

#endif // TCPSOCKETTHREAD_H
