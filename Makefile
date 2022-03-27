all:
	bison -d calc.y
	flex -+  -o calc.lex.cc calc.lex
	g++  -o calc calc.lex.cc calc.tab.cc -ll -lm
