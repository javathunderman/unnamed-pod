CC = gcc
CFLAGS = -I${INCLUDE} -pthread
CLINK = -L${INCLUDE} -lvs_can_api_x86-64
SRC = ./src
INCLUDE = ./include
COMM = ${SRC}/comm
STATES = ${SRC}/states
SENS = ${SRC}/sensors
CAN = ${SRC}/can

main: main_alg.o commands.o accelerate.o estop.o initialize.o normbrake.o service.o startup.o standby.o idle.o udp.o receiver.o telemetry.o spacex.o can_master.o can_handlers.o
	${CC} ${CFLAGS} -o main main_alg.o commands.o accelerate.o estop.o initialize.o normbrake.o service.o startup.o standby.o idle.o udp.o receiver.o telemetry.o spacex.o can_master.o can_handlers.o ${CLINK}

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

can_handlers.o: ${CAN}/can_handlers.c ${INCLUDE}/can_handlers.h ${INCLUDE}/can_master.h ${INCLUDE}/vs_can_api.h
	${CC} ${CFLAGS} -c ${CAN}/can_handlers.c

can_master.o: ${CAN}/can_master.c ${INCLUDE}/can_master.h ${INCLUDE}/can_handlers.h ${INCLUDE}/vs_can_api.h
	${CC} ${CFLAGS} -c ${CAN}/can_master.c

.PHONY: clean

clean:
	rm *.o
