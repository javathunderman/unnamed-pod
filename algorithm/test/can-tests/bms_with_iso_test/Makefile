CC = gcc
CFLAGS = -I${INCLUDE} -pthread
CLINK = -L${INCLUDE} -lvs_can_api_x86-64
SRC = ../../../main-comp-alg/src
INCLUDE = ../../../main-comp-alg/include
COMM = ${SRC}/comm
STATES = ${SRC}/states
SENS = ${SRC}/sensors
CAN = ${SRC}/can

main: bms_with_iso_driver.o can_master.o can_init.o can_handlers.o
	${CC} ${CFLAGS} -o bms_iso_test bms_with_iso_driver.o can_master.o can_init.o can_handlers.o ${CLINK}

bms_with_iso_driver.o: bms_with_iso_driver.c ${INCLUDE}/can_init.h ${INCLUDE}/can_master.h
	${CC} ${CFLAGS} -c bms_with_iso_driver.c

can_handlers.o: ${CAN}/can_handlers.c ${INCLUDE}/can_handlers.h ${INCLUDE}/can_master.h ${INCLUDE}/vs_can_api.h
	${CC} ${CFLAGS} -c ${CAN}/can_handlers.c

can_master.o: ${CAN}/can_master.c ${INCLUDE}/can_master.h ${INCLUDE}/can_handlers.h ${INCLUDE}/vs_can_api.h
	${CC} ${CFLAGS} -c ${CAN}/can_master.c

can_init.o: ${CAN}/can_init.c ${INCLUDE}/can_init.h ${INCLUDE}/can_master.h ${INCLUDE}/vs_can_api.h
	${CC} ${CFLAGS} -c ${CAN}/can_init.c

.PHONY: clean

clean:
	rm *.o
