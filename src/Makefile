BUILD_NAME=raycast

CC=gcc
OPT=2

PREFIX_SRC=
PREFIX_OBJ=

CFLUGS+= -Werror -O$(OPT) $()

$(BUILD_NAME) :
	$(CC) *.o -o $(BUILD_NAME) $(CFLUGS) -lraylib 

*.o : *.c
	$(CC) -c *.c -o *.o
