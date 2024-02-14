BUILD_NAME=raycast

CC=gcc
OPT=2

PREFIX_SRC= ./src/
PREFIX_OBJ= ./obj/

CFLUGS+= -Werror -O$(OPT) $()

$(BUILD_NAME) : $(PREFIX_OBJ)*.o
	$(CC) *.o -o $(BUILD_NAME) $(CFLUGS) -lraylib 

*.o : $(PREFIX_SRC)*.c
	$(CC) -c $(PREFIX_SRC)*.c -o *.o
