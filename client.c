#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8090

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char str[100];

    printf("\nInput the string:");
    scanf("%[^\n]s", str);

    if ((sock = socket(AF_INET,
                       SOCK_STREAM, 0))
        < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1",
                  &serv_addr.sin_addr)
        <= 0) {
        printf("\nAddress not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr,
                sizeof(serv_addr))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    int l = (int) strlen(str);

    send(sock, str, sizeof(str), 0);

    read(sock, str, l);

    printf("\nReversed string: \n");
    printf("%s\n", str);

    return 0;
} 
