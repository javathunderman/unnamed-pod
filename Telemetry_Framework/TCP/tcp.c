#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <pthread.h>
#include "telemetry.h"


#define SA struct sockaddr

void send_tlm(int socket);

void tcp_init(void) {
    int pod_socket, control_socket, len, opt = 1;
    struct sockaddr_in servaddr, client;

    /* Create pod socket */
    pod_socket = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(pod_socket, IPPROTO_TCP, TCP_NODELAY, (void *)&opt, sizeof(opt));
    if (pod_socket == -1) {
        printf("Socket creation failed...\n");
        exit(-1);
    } else {
        printf("Created socket...\n");
    }

    /* Bind pod socket to server address */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if ((bind(pod_socket, (SA *)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed...\n");
        printf("%s\n", strerror(errno));
        exit(-2);
    } else {
        printf("Bound socket...\n");
    }

    /* Listen for incoming connection */
    if (listen(pod_socket, 1) != 0) {
        printf("Listen failed...\n");
        exit(-3);
    } else {
        printf("Server listening...\n");
    }

    while(1) {
        /* Accept connection from COSMOS */
        len = sizeof(client);
        control_socket = accept(pod_socket, (SA *)&client, &len);
        setsockopt(control_socket, IPPROTO_TCP, TCP_NODELAY, (void *)&opt, sizeof(opt));
        if (control_socket < 0) {
            printf("Server accept failed...\n");
            exit(-4);
        } else {
            printf("Server accepted client...\n");
        }

        /* Begin receiving commands */


        /* Begin sending telemetry */
        send_tlm(control_socket);

        /* Join cmd and tlm threads before retrying */

    }
}
