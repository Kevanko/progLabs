APP = main

CFLAGS = -Wall 
DEPSFLAGS = -MMD

APP_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC = $(wildcard $(APP_DIR)/*.c)
OBJ = $(patsubst $(APP_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEPS = $(patsubst $(OBJ_DIR)/%.o,$(OBJ_DIR)/%.d,$(OBJ))

all: dir $(BIN_DIR)/$(APP)

dir:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/$(APP): $(OBJ)
	gcc $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(APP_DIR)/%.c
	cd $(APP_DIR) && gcc $(CFLAGS) $(DEPSFLAGS) -c -o ../$@ ../$<

-include $(DEPS)

clean:
	rm -f $(BIN_DIR)/$(APP)
	rm -rf $(OBJ_DIR)

