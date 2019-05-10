lab4_exe:main.o
	g++ main.o -o nombre_exe
main.o:lab4.cpp
	g++ -c lab4.cpp	
