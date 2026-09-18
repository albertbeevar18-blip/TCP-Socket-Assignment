#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int s, c;
    char msg[100];
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    s = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(s, (struct sockaddr *)&server, sizeof(server));
    listen(s, 5);

    printf("Server waiting...\n");

    c = accept(s, (struct sockaddr *)&client, &len);

    recv(c, msg, sizeof(msg), 0);
    printf("Client: %s\n", msg);

    strcpy(msg, "Hello Client");
    send(c, msg, strlen(msg) + 1, 0);

    close(c);
    close(s);

    return 0;
}
