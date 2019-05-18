calc: lex.yy.c y.tab.c
	g++ -g lex.yy.c y.tab.c -o calc

lex.yy.c: y.tab.c calc.l
	win_flex calc.l

y.tab.c: calc.y
	win_bison -d calc.y

clean: 
	rm -rf lex.yy.c calc.tab.c calc.tab.h calc calc.dSYM

