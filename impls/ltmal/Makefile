GPP = g++
FLAGS = -std=c++17 -g
INCLUDE = -I peelo-prompt/include
all: step0_repl.lt step1_read_print.lt


step1_read_print.lt: step1_read_print.cpp reader.cpp
	$(GPP) $(FLAGS) $(INCLUDE) $< -o step1_read_print

%.lt: %.cpp
	$(GPP) $(FLAGS) $(INCLUDE) $< -o $*

clean:
	rm step0_repl step1_read_print; rm -rf *.dSYM




.PHONY: all clean