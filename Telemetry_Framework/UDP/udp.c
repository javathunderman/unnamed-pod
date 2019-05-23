#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "telemetry.h"
#include "commands.h"
#include "receiver.h"

#define BUFF_LEN 100
#define US_IN_SEC 1000000

/* Global variables for thread arguments */
ReceiverArgs *ra;



int udp_init(CommandBuffer *cmd_buff) {
    int pod_socket;
    pthread_t recv_tid, send_tid;
    socklen_t dest_len;
    struct sockaddr_in servaddr, dest_addr;
    struct timeval timeout = {TO_USEC / US_IN_SEC, TO_USEC % US_IN_SEC};
    char buffer[BUFF_LEN];

    /* Create pod socket */
    pod_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (pod_socket == -1) {
        printf("Socket creation failed...\n");
        exit(-1);
    } else {
        printf("Created socket...\n");
    }

    /* Zero out servaddr and client */
    bzero(&servaddr, sizeof(servaddr));
    bzero(&dest_addr, sizeof(dest_addr));

    /* Setup pod server address */
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    /* Bind pod socket to server address */
    if ((bind(pod_socket, (SA *) &servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed...\n");
        printf("%s\n", strerror(errno));
        exit(-2);
    } else {
        printf("Bound socket...\n");
    }

    /* Accept connection from COSMOS */
    dest_len = sizeof(dest_addr);
    recvfrom(pod_socket, &buffer, BUFF_LEN, 0, (SA *) &dest_addr, &dest_len);
    dest_addr.sin_port = htons(PORT);
    printf("Received Command!!!\n");

    /* Configure socket with comm loss timeout */
    setsockopt(pod_socket, SOL_SOCKET, SO_RCVTIMEO, (void *) &timeout, sizeof(timeout));
    printf("Set SockOpt...\n");

    /* Begin receiving commands */
    ra->sock = pod_socket;
    ra->cb = cmd_buff;
    if (pthread_create(&recv_tid, NULL, recv_cmds, ra) != 0) {
        printf("recv_cmds pthread create failed...\n");
        exit(-3);
    }

    /* Begin sending telemetry */
    send_tlm(pod_socket, (SA *) &dest_addr, dest_len);

    /* Return success */
    return 0;
}
