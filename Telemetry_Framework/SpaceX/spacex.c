#include <sys/socket.h>
#include <stdio.h> 
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "telemetry.h"
#include "spacex.h"


/* Globals for Spacex communication */
int socket;
struct sockaddr_in spacex_addr;


int init_spacex(void) {
    
    /* Create SpaceX socket */
    socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket == -1) {
        printf("Socket creation failed...\n");
        return -1;
    } else {
        printf("Created socket...\n");
    }
    
    /* Configure address */
    bzero(&spacex_addr, sizeof(spacex_addr));
    spacex_addr.sin_family = AF_INET;
    spacex_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    spacex_addr.sin_port = htons(SPACEX_PORT);
    
}
