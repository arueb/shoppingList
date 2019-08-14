#   *********************************************************************
#   Program name: project2 makefile
#   Author: Alex Rueb
#   Date: 4/23/2017
#   Description: This is the makefile used to compile List.cpp,
#   Item.cpp, main.cpp, iVal.cpp and menu.cpp
#   (with corresponding header files) into object files plus the 
#   executable file 'project2' and runs valgrind.  The clean target 
#   removes all object files as well as the executable.  
#   *********************************************************************

project2: main.o Item.o List.o iVal.o menu.o
	g++ main.o Item.o List.o iVal.o menu.o -o project2
	valgrind project2

main.o: main.cpp
	g++ -c main.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

Die.o: List.cpp List.hpp
	g++ -c List.cpp

iVal.o: iVal.cpp iVal.hpp
	g++ -std=c++11 iVal.cpp -c

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

clean:
	rm *.o project2


