all : mainbin
	echo Compilation successfull

mainbin : main.cpp
	g++ -Wall -std=c++0x -pedantic -ggdb3 -O0 -o simbin main.cpp

