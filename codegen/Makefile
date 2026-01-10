all: parser

parser: syntax.tab.c lex.yy.c hashtable.c settings.h types.h symbol.h symbolTable.h semantics.h astinfo.h ast.h ir.h
	gcc -w syntax.tab.c lex.yy.c hashtable.c symbolTable.c types.c semantics.c ast.c ast_print.c codegen.c -lfl -o parser

syntax.tab.c: syntax.y settings.h
	bison  -d -o syntax.tab.c syntax.y 

lex.yy.c: comp.l
	flex comp.l

clean:
	rm -f parser syntax.tab.c syntax.tab.h lex.yy.c comp.output comp.tab.*