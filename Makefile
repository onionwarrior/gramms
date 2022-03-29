all:
	@echo "Building calc to runner"
	@bison -d calc.y &> /dev/null
	@flex -o calc.lex.cc calc.lex
	@g++  -o runner calc.lex.cc calc.tab.c driver.cpp runner.cpp -lm -std=c++17
clean:
	@echo "Cleaning up!"
	@yes | rm -f calc.tab.c calc.tab.h calc.lex.cc location.hh runner
