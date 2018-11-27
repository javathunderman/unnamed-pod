main: main_alg.c accelerate.o estop.o initialize.o normbrake.o service.o standby.o
	gcc -o main main_alg.c
	
accelerate.o: ./states/accelerate.c ./states/states.h
	gcc -c accelerate.c 
	
estop.o: ./states/estop.c ./states/states.h
	gcc -c estop.c 
	
initialize.o: ./states/initialize.c ./states/states.h
	gcc -c initialize.c 
	
normbrake.o: ./states/normbrake.c ./states/states.h
	gcc -c normbrake.c 
	
service.o: ./states/service.c ./states/states.h
	gcc -c service.c 

standby.o: ./states/standby.c ./states/states.h
	gcc -c standby.c 

.PHONY: clean

clean:
	rm -f *.o