# Makefile for Intel 8080 Emulator
# Written by:
#   Enzo Zamberlan <sincecontatodev@gmail.com>
# in July 2026

CC            = gcc
GCC_TARGET    := $(shell $(CC) -dumpmachine)

ifeq ($(findstring mingw32,$(GCC_TARGET)),mingw32)
  _WIN32 = 1
endif

SRC_PATH      = src
INCLUDE_PATH  = include
OBJ_DIR       = obj
BIN_DIR       = bin
INC_DIR       = -I. -I$(INCLUDE_PATH)

CCOPT         = -Wall -Wextra

DEBUG_ADD_FLAGS = -O2
ifdef DEBUG
  DEBUG_ADD_FLAGS = -g -ggdb -O0
endif

INTEL_EXEC = intel_emu

OBJS = \
	$(OBJ_DIR)/cpu.o \
	$(OBJ_DIR)/main.o \
	$(OBJ_DIR)/memory.o

all: clean directories $(BIN_DIR)/$(INTEL_EXEC)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(LOG_DIR)

directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR) $(LOG_DIR)

$(BIN_DIR)/$(INTEL_EXEC): $(OBJS)
	$(CC) $(LDOPT) -o $@ $(OBJS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c | directories
	$(CC) -c $(CCOPT) $(DEBUG_ADD_FLAGS) $(INC_DIR) $< -o $@

distclean: clean

.PHONY: all clean distclean directories