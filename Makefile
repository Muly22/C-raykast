BUILD_NAME=raycast

CC=gcc
OPT=2

PREFIX_SRC= ./src/
PREFIX_OBJ= ./obj/

SRC= main.c raycast_core.c raylib_window.c
OBJ= main.o raycast_core.o raylib_window.o

SRC:= $(addprefix $(PREFIX_SRC), $(SRC))
OBJ:= $(addprefix $(PREFIX_OBJ), $(OBJ))

CFLUGS+= -Werror -O$(OPT) -lraylib -lm 

$(BUILD_NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(BUILD_NAME) $(CFLUGS)

$(PREFIX_OBJ)%.o : $(PREFIX_SRC)%.c
	$(CC) -c $< -o $@

clean :
	rm $(BUILD_NAME)  $(PREFIX_OBJ)*.o
