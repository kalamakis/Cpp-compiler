# all: parser

# parser: syntax.tab.c lex.yy.c hashtable.c settings.h types.h symbol.h symbolTable.h semantics.h astinfo.h ast.h ir.h 
# 	gcc -w syntax.tab.c lex.yy.c hashtable.c symbolTable.c types.c semantics.c ast.c ast_print.c codegen.c finale_codegen.c -lfl -o parser

# syntax.tab.c: syntax.y settings.h
# 	bison  -d -o syntax.tab.c syntax.y 

# lex.yy.c: comp.l
# 	flex comp.l

# clean:
# 	rm -f parser syntax.tab.c syntax.tab.h lex.yy.c comp.output comp.tab.* ast.dot ast.png out.s out.asm a.out

# -------- Project --------
TARGET   := parser

# Sources you compile with gcc (NOT generated)
SRCS := hashtable.c symbolTable.c types.c semantics.c ast.c ast_print.c codegen.c finale_codegen.c

# Generated sources
BISON_Y := syntax.y
FLEX_L  := comp.l
BISON_C := syntax.tab.c
BISON_H := syntax.tab.h
FLEX_C  := lex.yy.c

# Objects
OBJS := $(SRCS:.c=.o) $(BISON_C:.c=.o) $(FLEX_C:.c=.o)

# Auto dependency files (.d)
DEPS := $(OBJS:.o=.d)

# -------- Tools --------
CC    := gcc
BISON := bison
FLEX  := flex

# -------- Flags --------
CPPFLAGS := -I.
CFLAGS_COMMON := -std=c11 -Wall -Wextra -Wpedantic -MMD -MP
LDFLAGS :=
LDLIBS  := -lfl

# build type: make (release) / make debug
CFLAGS_RELEASE := -O2
CFLAGS_DEBUG   := -O0 -g3 -DDEBUG

# Default: release
CFLAGS := $(CFLAGS_COMMON) $(CFLAGS_RELEASE)

# If you REALLY want to suppress warnings like before, uncomment:
CFLAGS += -w

# -------- Rules --------
.PHONY: all debug clean rebuild run

all: $(TARGET)

debug: CFLAGS := $(CFLAGS_COMMON) $(CFLAGS_DEBUG)
debug: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Bison generates both .c and .h
$(BISON_C) $(BISON_H): $(BISON_Y) settings.h
	$(BISON) -d -o $(BISON_C) $(BISON_Y)

# Flex depends on bison header if you include it in comp.l (common case)
$(FLEX_C): $(FLEX_L) $(BISON_H)
	$(FLEX) -o $(FLEX_C) $(FLEX_L)

# Compile C to object
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Include auto-generated dependencies (ignore missing)
-include $(DEPS)

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS) \
	      $(BISON_C) $(BISON_H) $(FLEX_C) \
	      comp.output comp.tab.* ast.dot ast.png out.s out.asm a.out

rebuild: clean all

# Optional helper
run: $(TARGET)
	./$(TARGET)
