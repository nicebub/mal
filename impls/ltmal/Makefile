GPP = g++
FLAGS = -std=c++17
INCLUDE = -I peelo-prompt/include
all: step0_repl.lt

%.lt: %.cpp
	$(GPP) $(FLAGS) $(INCLUDE) $< -o $*

clean:
	rm step0_repl




.PHONY: all clean