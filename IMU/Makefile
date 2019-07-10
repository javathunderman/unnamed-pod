#
#
# Author: Teunis van Beelen
#
# email: teuniz@protonmail.com
#
#

CC = gcc
CFLAGS = -Wall -Wextra -Wshadow -Wformat-nonliteral -Wformat-security -Wtype-limits -o2

objects = rs232.o

all: IMU

IMU : $(objects) IMU.o
	$(CC) $(objects) IMU.o -o IMU

IMU.o : IMU.c rs232.h
	$(CC) $(CFLAGS) -c IMU.c -o IMU.o

rs232.o : rs232.h rs232.c
	$(CC) $(CFLAGS) -c rs232.c -o rs232.o


#
#
#
#





