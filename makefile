CC=gcc
LEX=lex
YACC=bison -d
RM=rm -rf
CFLAGS= -Wall
LDFLAGS=
EXEC=compiler interpreter
SRC= list.c utils.c interpreter_table.c compiler_table.c
OBJ= $(SRC:.c=.o)
DEPS = list.h symbol.h utils.h interpreter_table.h compiler_table.h

all: $(EXEC)

compiler: lex.compiler.c compiler.tab.c $(OBJ)
	gcc lex.compiler.c compiler.tab.c $(SRC) -o compiler -ll -ly

interpreter: lex.interpreter_.c interpreter.tab.c $(OBJ)
	gcc lex.interpreter_.c interpreter.tab.c $(SRC) -o interpreter -ll -ly

%.o: $(DEPS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

lex.compiler.c: compiler.l
	$(LEX) compiler.l

compiler.tab.c: compiler.y
	$(YACC) compiler.y
    
lex.interpreter_.c: interpreter.l
	$(LEX) interpreter.l

interpreter.tab.c: interpreter.y
	$(YACC) interpreter.y

clean:
	$(RM) *.o

mrproper: clean
	$(RM) $(EXEC)
