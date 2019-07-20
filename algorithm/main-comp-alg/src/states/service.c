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
		if (!fpga->cache.brake_state){
			fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_True), "actuate brakes");
		}
	}
	else if (command == OPEN_ELECTRONIC_DRAIN_VALVE) {
		if (!fpga->cache.drain_valve_state){
			fpgaRunAndUpdateIf(fpga, write_actuate_drain(fpga, NiFpga_True), "open electronic drain valve");
		}
	}
	else if (command == FIRST_LOW_VOLTAGE_SHUTOFF){
		if (!fpga->cache.avb_shutoff_p1_state){
			fpgaRunAndUpdateIf(fpga, write_avb_shutoff_prim_1(fpga, NiFpga_True), "avb shutoff prim 1");
		}
	}
	else if (command == SECOND_LOW_VOLTAGE_SHUTOFF){
		if (!fpga->cache.avb_shutoff_p2_state){
			fpgaRunAndUpdateIf(fpga, write_avb_shutoff_prim_2(fpga, NiFpga_True), "avb shutoff prim 2");
		}
	}
	else if (command == FIRST_BATTERY_ON){
		if (fpga->cache.avb_shutoff_p1_state){
			fpgaRunAndUpdateIf(fpga, write_avb_shutoff_prim_1(fpga, NiFpga_False), "First battery on");
		}
	}
	else if (command == SECOND_BATTERY_ON){
		if (fpga->cache.avb_shutoff_p2_state){
			fpgaRunAndUpdateIf(fpga, write_avb_shutoff_prim_2(fpga, NiFpga_False), "Second battery on");
		}
	}
	else if (command == CLOSE_FIRST_RELAY){
		if (!fpga->cache.HVR_1_state){
			fpgaRunAndUpdateIf(fpga, write_hvr_1(fpga, NiFpga_True), "close HVR1");
		}	
	}
	else if (command == OPEN_FIRST_RELAY) {
		
		fpgaRunAndUpdateIf(fpga, write_hvr_1(fpga, NiFpga_False), "open HVR1");
			
	}
	else if (command == CLOSE_SECOND_RELAY){
		
		fpgaRunAndUpdateIf(fpga, write_hvr_2(fpga, NiFpga_True), "close HVR2");
			
	}
	else if (command == OPEN_SECOND_RELAY) {
		
		fpgaRunAndUpdateIf(fpga, write_hvr_2(fpga, NiFpga_False), "open HVR2");
			
	}
	else if (command == CLOSE_THIRD_RELAY){
		
		fpgaRunAndUpdateIf(fpga, write_hvr_3(fpga, NiFpga_True), "close HVR3");
		
	}
	else if (command == OPEN_THIRD_RELAY) {
		
		fpgaRunAndUpdateIf(fpga, write_hvr_3(fpga, NiFpga_False), "open HVR3");
			
	}
	else if (command == CLOSE_FOURTH_RELAY){
		
		fpgaRunAndUpdateIf(fpga, write_hvr_4(fpga, NiFpga_True), "close HVR4");
		
	}
	else if (command == OPEN_FOURTH_RELAY) {
		
		fpgaRunAndUpdateIf(fpga, write_hvr_4(fpga, NiFpga_False), "open HVR4");
		
	}
	else if (command == ENTER_PRE_CHARGE) {
		//verify that relay are switched according to the sequence
	}
	else if (command == ENTER_ENABLE_MOTOR){
		//verify relays are switched according to sequence
	}
	else if (command == RUN_ABORT){
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

