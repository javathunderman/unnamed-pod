main: main_alg.o commands.o accelerate.o estop.o initialize.o normbrake.o service.o startup.o standby.o idle.o
	gcc -o main main_alg.o commands.o accelerate.o estop.o initialize.o normbrake.o service.o startup.o standby.o idle.o -lpthread 
	
main_alg.o: main_alg.c ./states/states.h ./sensors/sensors.h
	gcc -c main_alg.c

commands.o: ../../../Telemetry_Framework/Commanding/commands.c ../../../Telemetry_Framework/Commanding/commands.h
	gcc -c ../../../Telemetry_Framework/Commanding/commands.c -lpthread 

accelerate.o: ./states/accelerate.c ./states/states.h
	gcc -c ./states/accelerate.c 
	
estop.o: ./states/estop.c ./states/states.h
	gcc -c ./states/estop.c 
	
initialize.o: ./states/initialize.c ./states/states.h
	gcc -c ./states/initialize.c 
	
normbrake.o: ./states/normbrake.c ./states/states.h
	gcc -c ./states/normbrake.c 
	
service.o: ./states/service.c ./states/states.h
	gcc -c ./states/service.c 

startup.o: ./states/startup.c ./states/states.h
	gcc -c ./states/startup.c 

standby.o: ./states/standby.c ./states/states.h
	gcc -c ./states/standby.c 

idle.o: ./states/idle.c ./states/states.h
	gcc -c ./states/idle.c 

.PHONY: clean

clean:
	rm *.o
