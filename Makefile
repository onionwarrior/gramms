all:
	bison -d calc.y
	flex -+ -o calc.lex.cc calc.lex
	g++  -o calc calc.lex.cc calc.tab.cc -ll -lm -std=c++17
clean:
	find . -regextype posix-egrep -regex '.*\.(cc|hh)$$' -delete
