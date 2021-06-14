
CC    	= gcc
BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = obj
TMP_DIR = tmp
FILES 	= $(shell ls $(SRC_DIR)/*.c)
OBJS  	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(FILES))


vpath %.c $(SRC_DIR)

.DEFAULT_GOAL = build

$(OBJ_DIR)/%.o: %.c
	$(CC) -Wall -g -c $^ -o $@

$(BIN_DIR): $(OBJS)
	$(CC) -g $^ -o $@

setup:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(TMP_DIR)

.PHONY: test # Run the tests
test:
	#@echo "Write some tests!"
	bin/aurras
	bin/aurras status
	bin/aurras transform samples/sample-1.m4a output.m4a alto eco rapido

.PHONY: b, build # Compilar o binário
b build: setup 
	
.PHONY: c, clean # Remover ficheiros gerados
c clean:
	@rm -r $(BIN_DIR) $(OBJ_DIR) $(TMP_DIR)

.PHONY: man, help # Generate list of targets with descriptions
man help:
	@echo -------------------------------------------------------------------+
	@grep '^.PHONY: .* #' Makefile | sed 's/\.PHONY: \(.*\) # \(.*\)/    \1 \t: \2\n-------------------------------------------------------------------+/'
