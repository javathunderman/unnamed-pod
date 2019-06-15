CC = gcc
CFLAGS = -I./include -pthread
SRC = ./src
INCLUDE = ./include
COMM = ${SRC}/comm
STATES = ${SRC}/states
SENS = ${SRC}/sensors

main: main_alg.o commands.o accelerate.o estop.o initialize.o normbrake.o service.o startup.o standby.o idle.o udp.o receiver.o telemetry.o spacex.o
	${CC} ${CFLAGS} -o main main_alg.o commands.o accelerate.o estop.o initialize.o normbrake.o service.o startup.o standby.o idle.o udp.o receiver.o telemetry.o spacex.o

main_alg.o: ${SRC}/main_alg.c ${INCLUDE}/states.h ${INCLUDE}/sensors.h ${INCLUDE}/commands.h ${INCLUDE}/udp.h
	${CC} ${CFLAGS} -c ${SRC}/main_alg.c

accelerate.o: ${STATES}/accelerate.c ${INCLUDE}/states.h
	${CC} ${CFLAGS} -c ${STATES}/accelerate.c 

estop.o: ${STATES}/estop.c ${INCLUDE}/states.h
	${CC} ${CFLAGS} -c ${STATES}/estop.c 

initialize.o: ${STATES}/initialize.c ${INCLUDE}/states.h
	${CC} ${CFLAGS} -c ${STATES}/initialize.c 

normbrake.o: ${STATES}/normbrake.c ${INCLUDE}/states.h
	${CC} ${CFLAGS} -c ${STATES}/normbrake.c 

service.o: ${STATES}/service.c ${INCLUDE}/states.h
	${CC} ${CFLAGS} -c ${STATES}/service.c 

startup.o: ${STATES}/startup.c ${INCLUDE}/states.h
	${CC} ${CFLAGS} -c ${STATES}/startup.c 

standby.o: ${STATES}/standby.c ${INCLUDE}/states.h
	${CC} ${CFLAGS} -c ${STATES}/standby.c 

idle.o: ${STATES}/idle.c ${INCLUDE}/states.h
	${CC} ${CFLAGS} -c ${STATES}/idle.c 

commands.o: ${COMM}/commands.c ${INCLUDE}/commands.h
	${CC} ${CFLAGS} -c ${COMM}/commands.c

udp.o: ${COMM}/udp.c ${INCLUDE}/commands.h ${INCLUDE}/receiver.h ${INCLUDE}/telemetry.h ${INCLUDE}/udp.h
	${CC} ${CFLAGS} -c ${COMM}/udp.c

receiver.o: ${COMM}/receiver.c ${INCLUDE}/commands.h ${INCLUDE}/receiver.h
	${CC} ${CFLAGS} -c ${COMM}/receiver.c 

telemetry.o: ${COMM}/telemetry.c ${INCLUDE}/telemetry.h
	${CC} ${CFLAGS} -c ${COMM}/telemetry.c

spacex.o: ${COMM}/spacex.c ${INCLUDE}/spacex.h ${INCLUDE}/telemetry.h
	${CC} ${CFLAGS} -c ${COMM}/spacex.c

.PHONY: clean

clean:
	rm *.o
