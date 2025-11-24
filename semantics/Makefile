all: parser

parser: syntax.tab.c lex.yy.c hashtable.c settings.h functions.h functions.c
	gcc -w syntax.tab.c lex.yy.c hashtable.c functions.c  -lfl -o parser

syntax.tab.c: syntax.y settings.h
	bison -d -o syntax.tab.c syntax.y

lex.yy.c: comp.l
	flex comp.l

clean:
	rm -f parser syntax.tab.c syntax.tab.h lex.yy.c comp.output