BUILD_NAME=raycast
BUILD_STATUS:=DEBUG


CC=gcc
OPT=2

PREFIX_SRC= ./src/
PREFIX_OBJ= ./obj/
PREFIX_BIN= ./bin/

SRC= main.c raycast_core.c rwindow.c rerror.c
OBJ= main.o raycast_core.o rwindow.o rerror.o

SRC:= $(addprefix $(PREFIX_SRC), $(SRC))
OBJ:= $(addprefix $(PREFIX_OBJ), $(OBJ))
BUILD_NAME:= $(addprefix $(PREFIX_BIN), $(BUILD_NAME))

FLUGS+= -Werror -O$(OPT) -lm -lX11 

ifeq ($(BUILD_STATUS),DEBUG)
	CFLUGS+= -D DEBUG
endif
$(BUILD_NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(BUILD_NAME) $(FLUGS)

$(PREFIX_OBJ)%.o : $(PREFIX_SRC)%.c
	$(CC) -c $< -o $@ $(CFLUGS)

clean :
	rm $(BUILD_NAME)  $(PREFIX_OBJ)*.o
