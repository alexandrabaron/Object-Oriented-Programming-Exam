Nation.o : Nation.h Nation.cpp
	g++ -c Nation.cpp

TabNations.o : Nation.h TabNations.h TabNations.cpp
	g++ -c TabNations.cpp
	
TabMedailles.o : Nation.h TabNations.h TabMedailles.h TabMedailles.cpp
	g++ -c TabMedailles.cpp

main.o : Nation.h TabNations.h TabMedailles.h main.cpp
	g++ -c main.cpp

OBJ = Nation.o TabNations.o TabMedailles.o main.o

main : $(OBJ)
	g++ $(OBJ) -o main
