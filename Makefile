SHELL := /usr/bin/env bash

CC      ?= gcc
FLEX    ?= flex
BISON   ?= bison

SRC_DIR   := src
BUILD_DIR := build
GEN_DIR   := $(BUILD_DIR)/generated
OBJ_DIR   := $(BUILD_DIR)/obj
BIN_DIR   := bin
TARGET    := $(BIN_DIR)/gcpp

CPPFLAGS ?=
CPPFLAGS += -I$(SRC_DIR) -I$(GEN_DIR)

CFLAGS ?= -g -O0
CFLAGS += -std=gnu11 -MMD -MP

LDFLAGS ?=
LDLIBS  ?=

CORE_SOURCES := \
  hashtable.c \
  symbolTable.c \
  types.c \
  semantics.c \
  ast.c \
  ast_print.c \
  ir.c \
  codegen.c

CORE_OBJECTS := $(addprefix $(OBJ_DIR)/,$(CORE_SOURCES:.c=.o))
GENERATED_OBJECTS := $(OBJ_DIR)/syntax.tab.o $(OBJ_DIR)/lex.yy.o
OBJECTS := $(GENERATED_OBJECTS) $(CORE_OBJECTS)
DEPS := $(OBJECTS:.o=.d)

PARSER_C := $(GEN_DIR)/syntax.tab.c
PARSER_H := $(GEN_DIR)/syntax.tab.h
PARSER_STAMP := $(GEN_DIR)/parser.stamp
LEXER_C := $(GEN_DIR)/lex.yy.c

.DEFAULT_GOAL := all

.PHONY: all build setup run test clean check-tools help

all: build

build: check-tools $(TARGET)

check-tools:
	@command -v "$(CC)" >/dev/null 2>&1 || { echo "Missing C compiler: $(CC)" >&2; exit 1; }
	@command -v "$(FLEX)" >/dev/null 2>&1 || { echo "Missing Flex. Run ./scripts/setup.sh" >&2; exit 1; }
	@command -v "$(BISON)" >/dev/null 2>&1 || { echo "Missing Bison. Run ./scripts/setup.sh" >&2; exit 1; }

$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(PARSER_STAMP): $(SRC_DIR)/syntax.y $(SRC_DIR)/settings.h | $(GEN_DIR)
	$(BISON) -d -o $(PARSER_C) $(SRC_DIR)/syntax.y
	@touch $@

$(PARSER_C) $(PARSER_H): $(PARSER_STAMP)

$(LEXER_C): $(SRC_DIR)/comp.l $(PARSER_H) | $(GEN_DIR)
	$(FLEX) -o $@ $<

$(OBJ_DIR)/syntax.tab.o: $(PARSER_C) $(PARSER_H) | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(PARSER_C) -o $@

$(OBJ_DIR)/lex.yy.o: $(LEXER_C) $(PARSER_H) | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(LEXER_C) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR) $(GEN_DIR) $(OBJ_DIR) $(BIN_DIR):
	@mkdir -p $@

setup:
	@./scripts/setup.sh

run: build
	@if [[ -z "$(INPUT)" ]]; then \
		echo "Usage: make run INPUT=examples/arrays_and_functions.cpp [OUTPUT=output/program.asm]" >&2; \
		exit 2; \
	fi
	@./scripts/run.sh --no-build "$(INPUT)" $(if $(OUTPUT),"$(OUTPUT)",)

test: build
	@./scripts/test.sh --no-build

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) output

help:
	@printf '%s\n' \
	  'Targets:' \
	  '  make              Build bin/gcpp' \
	  '  make setup        Install/check build dependencies' \
	  '  make run INPUT=... [OUTPUT=...]' \
	  '                    Compile one CPP source file' \
	  '  make test         Run smoke tests over all examples' \
	  '  make clean        Remove generated files' \
	  '' \
	  'Variables: CC, FLEX, BISON, CPPFLAGS, CFLAGS, LDFLAGS, LDLIBS'

-include $(DEPS)
