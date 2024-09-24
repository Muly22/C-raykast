TARGET = raycast

CC = gcc
MKDIR = mkdir -p
OPT = 2

SRC_PATH = ./src/
OBJ_PATH = ./obj/
BIN_PATH = ./bin/

SRC = $(shell find $(SRC_PATH) -type f -name '*.c')
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o,$(SRC))

CFLAGS+= -O$(OPT)
LDFLAGS+= -Wall -lm

.PHONY: all clean

all: $(BIN_PATH)$(TARGET)

$(BIN_PATH)$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFAUGS) $(LDFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(MKDIR) $(@D)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm $(BIN_PATH)$(TARGET) $(OBJ_PATH)*.o
