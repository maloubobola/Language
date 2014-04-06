CC=gcc
LEX=lex
YACC=yacc -d
RM=rm -rf
CFLAGS=-Wall
LDFLAGS=
EXEC=lexical
SRC= list.c symbol.c utils.c
OBJ= $(SRC:.c=.o)
DEPS = list.h symbol.h utils.h

all: $(EXEC)

lexical: lex.yy.c y.tab.c $(OBJ)
	gcc lex.yy.c y.tab.c $(SRC) -o lexical -ll -ly

%.o: $(DEPS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

lex.yy.c: lexical.l
	$(LEX) lexical.l

y.tab.c: lexical.y
	$(YACC) lexical.y

clean:
	$(RM) *.o

mrproper: clean
	$(RM) $(EXEC)