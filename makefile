all : mainbin
	# Compilation successfull?

mainbin : main.cpp
	g++ -Wall -std=c++0x -pedantic -ggdb3 -O0 -o mainbin main.cpp
