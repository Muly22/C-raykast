TARGET = raycast

CC = gcc
OPT = 2

SRC_PATH = ./src/
OBJ_PATH = ./obj/
BIN_PATH = ./bin/

SRC = $(shell find $(SRC_PATH) -type f -name '*.c')
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o,$(SRC))

SRC:= $(addprefix $(SRC_PATH), $(SRC))
OBJ:= $(addprefix $(OBJ_PATH), $(OBJ))

CFLUGS+= -O$(OPT)
LDFLUGS+= -Wall -lm

.PHONY: all clean

all: $(BIN_PATH)$(TARGET)

$(BIN_PATH)$(TARGET): $(OBJ)
	$(CC) -o $@ &^ $(CFLUGS) $(LDFLAGS)

$(OBJ_PATH)%.o: $(SRC_PAHT)%.c
	$(CC) -c $< -o $@ $(CFLUGS)

clean:
	rm $(BIN_PATH)$(TARGET) $(OBJ_PATH)*.o
