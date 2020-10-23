#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFF_LEN 210
#define US_IN_SEC 1000000
#define SA struct sockaddr

typedef struct {
  unsigned int TBM_TEMP : 32;
  unsigned int EPB_PRESSURE : 32;
  unsigned int ACCEL_X : 32;
  unsigned int ACCEL_Y : 32;
  unsigned int ACCEL_Z : 32;
  unsigned int VEL_X : 32;
  unsigned int VEL_Y : 32;
  unsigned int VEL_Z : 32;
  unsigned int POS_X : 32;
  unsigned int POS_Y : 32;
  unsigned int POS_Z : 32;
  unsigned int PRIM1_V : 32;
  unsigned int PRIM2_V : 32;
  unsigned int RESV_V : 32;
  unsigned int PRIM1_A : 32;
  unsigned int PRIM2_A : 32;
  unsigned int RESV_A : 32;
  unsigned int PRIM1_TEMP : 32;
  unsigned int PRIM2_TEMP : 32;
  unsigned int RESV_TEMP : 32;
  unsigned int MTR_RPM : 32;
  unsigned int MTR_V : 32;
  unsigned int MTR_A : 32;
  unsigned int MTR_TEMP : 32;
  unsigned int CAN_CONNECTED : 32;
  unsigned int INT_HYD_TEMP : 32;
  unsigned int EXT_HYD_TEMP : 32;
  unsigned int CIM_SPEED : 32;
  unsigned int SOIL_BOX_WEIGHT : 32;
  unsigned int FSM_STATE : 32;
  unsigned int INIT_CHECKS : 32;
  unsigned int TIME_SEC : 32;
  unsigned int TIME_USEC : 32;
  unsigned int LAST_COMMAND : 32;
  unsigned int THROTTLE : 32;
} Telemetry;

void main(void) {
    Telemetry tlm;
    int pod_socket;
    int dest_len;
    struct sockaddr_in servaddr, dest_addr;
    //struct timeval timeout = {TO_USEC / US_IN_SEC, TO_USEC % US_IN_SEC};
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
    servaddr.sin_port = htons(55003);

    dest_addr.sin_family = AF_INET;
    inet_aton("192.168.1.127", &dest_addr.sin_addr.s_addr);
    dest_addr.sin_port = htons(8187);

    /* Bind pod socket to server address */
    if ((bind(pod_socket, (SA *) &servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed...\n");
        printf("%s\n", strerror(errno));
        exit(-2);
    } else {
        printf("Bound socket...\n");
    }

    update_telemetry_1_1(&tlm);

    printf("Sending...\n");
    if(sendto(pod_socket, &tlm, 228, MSG_NOSIGNAL, (SA *) &dest_addr, sizeof(dest_addr)) == -1) {
        printf("%s\n", strerror(errno));
    }
    printf("Done\n");

    /* Accept connection from COSMOS */
    //recvfrom(pod_socket, &buffer, BUFF_LEN, MSG_WAITALL, (SA *) &dest_addr, &dest_len);

    /* Configure socket with comm loss timeout */
    //setsockopt(pod_socket, SOL_SOCKET, SO_RCVTIMEO, (void *) &timeout, sizeof(timeout));

    /* Begin receiving commands */

    /* Begin sending telemetry */
    //send_tlm(pod_socket, (SA *) &dest_addr, sizeof(dest_addr));
}

void update_telemetry_1_1(Telemetry *tlm) {
    tlm->TBM_TEMP = 0x42b2cccd;
    tlm->EPB_PRESSURE = 0x3e5ba5e3;
    tlm->ACCEL_X = 0x401e147b;
    tlm->ACCEL_Y = 0x3ab78034;
    tlm->ACCEL_Z = 0xba902de0;
    tlm->VEL_X = 0x43598000;
    tlm->VEL_Y = 0x00000000;
    tlm->VEL_Z = 0x00000000;
    tlm->POS_X = 0x439c0000;
    tlm->POS_Y = 0x3c23d70a;
    tlm->POS_Z = 0x3c23d70a;
    tlm->PRIM1_V = 0x41e00000;
    tlm->PRIM2_V = 0x41e00002;
    tlm->RESV_V = 0x41e00000;
    tlm->PRIM1_A = 0x4174cccd;
    tlm->PRIM2_A = 0x41080000;
    tlm->RESV_A = 0x41080000;
    tlm->PRIM1_TEMP = 0x42c06666;
    tlm->PRIM2_TEMP = 0x42c06666;
    tlm->RESV_TEMP = 0x42c06666;
    tlm->MTR_RPM = 0x4552e000;
    tlm->MTR_V = 0x4426d333;
    tlm->MTR_A = 0x435ab333;
    tlm->MTR_TEMP = 0x438b91ec;
    tlm->CAN_CONNECTED = 1;
    tlm->INT_HYD_TEMP = 0x42c80000;
    tlm->EXT_HYD_TEMP = 0x447a0000;
    tlm->CIM_SPEED = 0x00000000;
    tlm->SOIL_BOX_WEIGHT = 0x40a00000;
    tlm->FSM_STATE = 0;
    tlm->INIT_CHECKS = 0;
    tlm->TIME_SEC = 0;
    tlm->TIME_USEC = 0;
    tlm->LAST_COMMAND = 0;
    tlm->THROTTLE = 0;
}
