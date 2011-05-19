#ifndef CLIENT_H
#define CLIENT_H

#include <QThread>

struct cmd_t;

class Client : public QThread
{
    Q_OBJECT

public:
    Client(QString addr, QString port, QString path, QString name, QString arg);

protected:
    void run();

private:
    QString addr;
    int port;
    QString path;
    QString name;
    QString arg;

    int server_connect(const char *ip, short port);
    void send_cmd(int s, cmd_t cmd);

signals:
    void dataReceived(QString text);
    void connectError();
};

#endif // CLIENT_H
