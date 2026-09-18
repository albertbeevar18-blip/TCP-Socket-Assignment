#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int s;
    char msg[100];
    struct sockaddr_in server;

    s = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(s, (struct sockaddr *)&server, sizeof(server));

    strcpy(msg, "Hello Server");
    send(s, msg, strlen(msg) + 1, 0);

    recv(s, msg, sizeof(msg), 0);
    printf("Server: %s\n", msg);

    close(s);

    return 0;
}
