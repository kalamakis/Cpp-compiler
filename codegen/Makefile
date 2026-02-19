# -------- Config --------
CC      := gcc
CFLAGS  :=-g 
CPPFLAGS:= -I. 
LDFLAGS :=
LDLIBS  := -lfl

TARGET  := gcpp

SRCS := \
  syntax.tab.c \
  lex.yy.c \
  hashtable.c \
  symbolTable.c \
  types.c \
  semantics.c \
  ast.c \
  ast_print.c \
  ir.c \
  codegen.c

OBJS := $(SRCS:.c=.o)
DEPS := $(OBJS:.o=.d)

# -------- Default --------
all: $(TARGET)

# -------- Link --------
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@ 

# -------- Compile (auto header deps) --------
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS)  -c $< -o $@

# -------- Bison/Flex --------
syntax.tab.c syntax.tab.h: syntax.y settings.h
	bison -d -o syntax.tab.c syntax.y

lex.yy.c: comp.l
	flex -o lex.yy.c comp.l

# Ensure generated C files exist before compiling them
syntax.tab.o: syntax.tab.c syntax.tab.h
lex.yy.o: lex.yy.c syntax.tab.h

# -------- Utilities --------
clean:
	rm -f $(TARGET) $(OBJS) $(DEPS) \
	      syntax.tab.c syntax.tab.h lex.yy.c \
	      comp.output comp.tab.* \
	      ast.dot ast.png out.s out.asm a.out

.PHONY: all clean

# -------- Include auto-generated deps --------
-include $(DEPS)
