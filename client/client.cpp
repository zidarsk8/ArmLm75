#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> /* struct sockaddr_in, ... */
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include "defs.h"
#include "client.h"

Client::Client(QString addr, QString port, QString path, QString name, QString arg)
{
    this->addr = addr;
    this->port = port.toInt();
    this->path = path;
    this->name = name;
    this->arg = arg;
}

int Client::server_connect(const char *ip, short port)
{
    int s, e;
    struct sockaddr_in server_addr;

    s = socket(PF_INET, SOCK_STREAM, 0);
    if (s < 0) return -1;

    memset((void *) &server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    e = ::connect(s, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (e) return -1;

    return s;
}

void Client::send_cmd(int s, cmd_t cmd)
{
    char buf[81];
    int n;

    write(s, (void *) &cmd, sizeof(cmd));
    while ((n = read(s, (void *) buf, sizeof(buf)-1)) > 0) {
        buf[n] = '\0';
        emit dataReceived(buf);
        //qDebug(buf);
    }
}

void Client::run()
{
    //TODO: custom port
    int s;
    struct cmd_t cmd;
    int connPort = SERVER_PORT;
    if (port > 0){
        connPort = port;
    }

    strcpy(cmd.path, path.toLatin1().data());
    strcpy(cmd.name, name.toLatin1().data());
    strcpy(cmd.arg, arg.toLatin1().data());

    s = server_connect(addr.toLatin1().data(), connPort);
    if (s < 0) {
        emit connectError();
        return;
    }

    send_cmd(s, cmd);

    ::close(s);
}
