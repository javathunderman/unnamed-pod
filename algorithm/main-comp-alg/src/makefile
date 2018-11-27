main: main_alg.c accelerate.o estop.o initialize.o normbrake.o service.o standby.o
	gcc -o main main_alg.c
	
accelerate.o: accelerate.c states.h
	gcc -c accelerate.c 
	
estop.o: estop.c states.h
	gcc -c estop.c 
	
initialize.o: initialize.c states.h
	gcc -c initialize.c 
	
normbrake.o: normbrake.c states.h
	gcc -c normbrake.c 
	
service.o: service.c states.h
	gcc -c service.c 

standby.o: standby.c states.h
	gcc -c standby.c 

.PHONY: clean

clean:
	rm -f *.o