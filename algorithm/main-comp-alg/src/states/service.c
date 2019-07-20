#ifndef __SERVICE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"
#include "fpga_cache.h"


#define __SERVICE__
#endif

int service_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf(">> SERVICE STATE\n");

	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	else if (command == ENTER_STANDBY) { //&&velocity == 0
		printf("Exiting service -> Standby\n");
		return STANDBY_SID;
	}
	else if (command == STOP_SERVICE_PROPULSION) {
		//stop motor
	}
	else if (command == FORWARD_SERVICE_PROPULSION) {
		//motor forward
		printf("Forward Command Received\n");
	}
	else if (command == BACKWARD_SERVICE_PROPULSION) {
		//motor backward
		printf("Backward Command Received\n");
	}
	else if (command == SLOW_SERVICE_PROPULSION) {
		//motor speed slow
		printf("Slow Command Received\n");
	}
	else if (command == MEDIUM_SERVICE_PROPULSION) {
		//motor speed medium
	}
	else if (command == FAST_SERVICE_PROPULSION) {
		//motor speed fast
	}
	else if (command == ACTUATE_BRAKES) {
		//verify both solenoids open or that digital output is low for two brake solenoids
	}
	else if (command == OPEN_ELECTRONIC_DRAIN_VALVE) {
		//verify solenoid open or digital output is high for drain solenoid	
	}
	else if (command == FIRST_LOW_VOLTAGE_SHUTOFF){
		//verify current drops to precision of zero for first battery
	}
	else if (command == SECOND_LOW_VOLTAGE_SHUTOFF){
		//verify current drops to precision of zero for second battery and verify avionics load is on reserve battery
	}
	else if (command == FIRST_BATTERY_ON){
		//verify current is non zero for first battery
	}
	else if (command == SECOND_BATTERY_ON){
		//verify current is non zero for second battery	
	}
	else if (command == CLOSE_FIRST_RELAY){
		//verify control pin on flight computer is pulled high 	
	}
	else if (command == OPEN_FIRST_RELAY) {
		//verify that pin on flight computer is pulled low	
	}
	else if (command == CLOSE_SECOND_RELAY){
		//verify control pin on flight computer is pulled high 	
	}
	else if (command == OPEN_SECOND_RELAY) {
		//verify that pin on flight computer is pulled low	
	}
	else if (command == CLOSE_THIRD_RELAY){
		//verify control pin on flight computer is pulled high 	
	}
	else if (command == OPEN_THIRD_RELAY) {
		//verify that pin on flight computer is pulled low	
	}
	else if (command == CLOSE_FOURTH_RELAY){
		//verify control pin on flight computer is pulled high 	
	}
	else if (command == OPEN_FOURTH_RELAY) {
		//verify that pin on flight computer is pulled low	
	}
	else if (command == ENTER_PRE_CHARGE) {
		//verify that relay are switched according to the sequence
	}
	else if (command == ENTER_ENABLE_MOTOR){
		//verify relays are switched according to sequence
	}
	else if (command == ABORT_RUN){
		//abort using E-stop	
	}
	else if (command == SLEEP){
		//state machine freezes for 1 second	
	}
	else if (command == ENTER_SERVICE_PROPULSION){
		//enters service propulsion	
	}
	else if (command == BEGIN_MOTOR_CONTROLLER_STARTUP){
		//pre charge motor begins motor controller startup
	}
	else if (command == SET_MOTOR_CONTROLLER_ACTIVE){
		//Enable motor puts motor controller in active state	
	}
	else if (command == FREE_SPIN_MOTOR){
		//slow service propulsion free spins the motor at 5mph	
	}
	//repeat
	return SERVICE_SID;
}

