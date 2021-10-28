#ifndef CONNECTIONACCEPTOR_H
#define CONNECTIONACCEPTOR_H

#include <QObject>
#include <QTcpServer>

class ConnectionAcceptor : public QTcpServer
{
    Q_OBJECT
public:
    explicit ConnectionAcceptor(const QString& address, const quint16 port, QObject* parent = nullptr);

private slots:
    void incomingConnection(qintptr handle) override;
};

#endif // CONNECTIONACCEPTOR_H
