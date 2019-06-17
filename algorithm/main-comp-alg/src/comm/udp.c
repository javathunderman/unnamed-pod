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
ReceiverArgs ra;
TelemetryArgs ta;

/* This function initializes external communication via UDP.
 * This function will wait to receive one message from the host and then
 * launch 3 communication threads.
 *     1) Command Receiver Thread
 *     2) Pod Telemetry Thread (to host)
 *     3) Special Telemetry Thread (to SpaceX)
 *
 * Params:
 *     CommandBuffer *cb -> pointer to initialized CommandBuffer
 *
 * Returns:
 *      0 -> success
 *     -1 -> socket creation failure
 *     -2 -> socket bind failure
 *     -3 -> recvfrom failure
 *     -4 -> setsockopt failure
 *     -5 -> cmd thread creation failure
 *     -6 -> tlm thread creation failure
 */
int udp_init(CommandBuffer *cb) {
    int pod_socket;
    pthread_t recv_tid, send_tid;
    socklen_t dest_len;
    struct sockaddr_in servaddr, dest_addr;
    struct timeval timeout = {TO_USEC / US_IN_SEC, TO_USEC % US_IN_SEC};
    char buffer[BUFF_LEN];

    /* Create pod socket */
    pod_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (pod_socket == -1) {
        printf("Pod socket creation failed...\n");
        return -1;
    } else {
        printf("Created pod socket...\n");
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
        return -2;
    } else {
        printf("Bound socket...\n");
    }

    /* Accept connection from COSMOS */
    dest_len = sizeof(dest_addr);
    if (recvfrom(pod_socket, &buffer, BUFF_LEN, 0, (SA *) &dest_addr, &dest_len) == -1) {
        printf("COSMOS connection failed at recvfrom()\n");
        return -3;
    } else {
        printf("Received COSMOS connection!\n");
    }
    dest_addr.sin_port = htons(PORT);


    /* Configure socket with comm loss timeout */
    if (setsockopt(pod_socket, SOL_SOCKET, SO_RCVTIMEO, (void *) &timeout, sizeof(timeout)) == -1) {
        printf("setsockopt failure...\n");
        return -4;
    } else {
        printf("Set timeout sockopt...\n");
    }

    /* Begin receiving commands */
    ra.sock = pod_socket;
    ra.cb = cb;
    if (pthread_create(&recv_tid, NULL, recv_cmds, &ra) != 0) {
        printf("recv_cmds pthread create failed...\n");
        return -5;
    } else {
        printf("Created receiver thread...\n");
    }

    /* Begin sending telemetry */
    ta.socket = pod_socket;
    ta.dest_addr = (SA *) &dest_addr;
    ta.dest_len = dest_len;
    if (pthread_create(&send_tid, NULL, send_tlm, &ta) != 0) {
        printf("send_tlm pthread create failed...\n");
        return -6;
    } else {
        printf("Created telemetry thread...\n");
    }

    /* Return success */
    //TODO something with tids
    return 0;
}
