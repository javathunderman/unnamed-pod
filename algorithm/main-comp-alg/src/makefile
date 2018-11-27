main: main_alg.c ./states/states.h ./sensors/sensors.h accelerate.o estop.o initialize.o normbrake.o service.o standby.o
	gcc -o main main_alg.c accelerate.o estop.o initialize.o normbrake.o service.o standby.o
	
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

standby.o: ./states/standby.c ./states/states.h
	gcc -c ./states/standby.c 

.PHONY: clean

clean:
	rm -f *.o