#include <stdio.h>
#include <time.h>
#include "can_master.h"
#include "vs_can_api.h"


VSCAN_MSG request_lookup[NUM_CAN_REQUESTS];
VSCAN_MSG response_lookup[NUM_CAN_RESPONSES];


/* This function intializes a connection to the NetCAN device.
 * This function must run successfully before any CAN messages are
 * sent or received.
 *
 * Params:
 *     None
 *
 * Returns:
 *      0 -> success
 *     -1 -> VSCAN_Open failure
 *     -2 -> bitrate configuration failure
 */
int can_init() {
    VSCAN_HANDLE h = -1;
    DWORD rv, bitrate = 500000;
    char *tty = "10.25.37.4:2001"; //TODO: Verify IP
    
    /* Establish connection to NetCAN device */
    h = VSCAN_Open(tty, VSCAN_MODE_NORMAL);
    if (h <= 0) {
        printf("Could not connect to NetCAN device!\n");
        return -1;
    }
    
    /* Set CAN bus bitrate */
    if (VSCAN_Ioctl(h, VSCAN_IOCTL_SET_SPEED, (void *)bitrate) != VSCAN_ERR_OK) {
        printf("Setting CAN speed failed");
        return -2;
    }
    
    
    /* Create VSCAN_MSGs that will be used during the run */
    init_can_requests();
    init_can_responses();
}

void init_can_requests() {
    /* ISO_STATE_TX */
    request_lookup[ISO_STATE_TX].Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[ISO_STATE_TX].Id = 0xA100101;
    request_lookup[ISO_STATE_TX].Size = 1;
    request_lookup[ISO_STATE_TX].Data[0] = 0xE0;
    
    /* ISO_RESISTANCE_TX */
    request_lookup[ISO_RESISTANCE_TX].Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[ISO_RESISTANCE_TX].Id = 0xA100101;
    request_lookup[ISO_RESISTANCE_TX].Size = 1;
    request_lookup[ISO_RESISTANCE_TX].Data[0] = 0xE1;
    
    /* ISO_ERROR_TX */
    request_lookup[ISO_ERROR_TX].Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[ISO_ERROR_TX].Id = 0xA100101;
    request_lookup[ISO_ERROR_TX].Size = 1;
    request_lookup[ISO_ERROR_TX].Data[0] = 0xE5;
    
    /* LIPO_VOLTAGE_TX */
    request_lookup[LIPO_VOLTAGE_TX].Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[LIPO_VOLTAGE_TX].Id = 0xA100101;
    request_lookup[LIPO_VOLTAGE_TX].Size = 1;
    request_lookup[LIPO_VOLTAGE_TX].Data[0] = 0xE4;
}

void init_can_responses() {
    
}

void *can_master(void *args) {
    
}
