CC = gcc
CFLAGS = -I${COMM} -I${STATES} -pthread
COMM = ./comm
STATES = ./states
SENS = ./sensors

main: main_alg.o commands.o accelerate.o estop.o initialize.o normbrake.o service.o startup.o standby.o idle.o udp.o receiver.o telemetry.o spacex.o
	${CC} ${CFLAGS} -o main main_alg.o commands.o accelerate.o estop.o initialize.o normbrake.o service.o startup.o standby.o idle.o udp.o receiver.o telemetry.o spacex.o

main_alg.o: main_alg.c ${STATES}/states.h ${SENS}/sensors.h ${COMM}/commands.h ${COMM}/udp.h
	${CC} ${CFLAGS} -c main_alg.c

accelerate.o: ${STATES}/accelerate.c ${STATES}/states.h
	${CC} ${CFLAGS} -c ${STATES}/accelerate.c 

estop.o: ${STATES}/estop.c ${STATES}/states.h
	${CC} ${CFLAGS} -c ${STATES}/estop.c 

initialize.o: ${STATES}/initialize.c ${STATES}/states.h
	${CC} ${CFLAGS} -c ${STATES}/initialize.c 

normbrake.o: ${STATES}/normbrake.c ${STATES}/states.h
	${CC} ${CFLAGS} -c ${STATES}/normbrake.c 

service.o: ${STATES}/service.c ${STATES}/states.h
	${CC} ${CFLAGS} -c ${STATES}/service.c 

startup.o: ${STATES}/startup.c ${STATES}/states.h
	${CC} ${CFLAGS} -c ${STATES}/startup.c 

standby.o: ${STATES}/standby.c ${STATES}/states.h
	${CC} ${CFLAGS} -c ${STATES}/standby.c 

idle.o: ${STATES}/idle.c ${STATES}/states.h
	${CC} ${CFLAGS} -c ${STATES}/idle.c 

commands.o: ${COMM}/commands.c ${COMM}/commands.h
	${CC} ${CFLAGS} -c ${COMM}/commands.c

udp.o: ${COMM}/udp.c ${COMM}/commands.h ${COMM}/receiver.h ${COMM}/telemetry.h ${COMM}/udp.h
	${CC} ${CFLAGS} -c ${COMM}/udp.c

receiver.o: ${COMM}/receiver.c ${COMM}/commands.h ${COMM}/receiver.h
	${CC} ${CFLAGS} -c ${COMM}/receiver.c 

telemetry.o: ${COMM}/telemetry.c ${COMM}/telemetry.h
	${CC} ${CFLAGS} -c ${COMM}/telemetry.c

spacex.o: ${COMM}/spacex.c ${COMM}/spacex.h ${COMM}/telemetry.h
	${CC} ${CFLAGS} -c ${COMM}/spacex.c

.PHONY: clean

clean:
	rm *.o
