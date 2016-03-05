##
## Makefile 
##


## Define compiler

CC	= g++

## Define flags

CFLAGS	= -Wall -Wshadow -Werror -g -std=c++11

## Build rule to build executable, by default, Main is build since it 
## is the label of the first rule

Main: Main.o First_Person.o Isometric_Render.o World_Map.o EasyBMP.o 
	$(CC) $(CFLAGS) Main.cpp First_Person.cpp Isometric_Render.cpp World_Map.cpp EasyBMP.o -o Main
## rule to clean up object files and executable so that you can rebuild

##clean:	
##	rm -f Main.o bmp.o First_Person.o Isometric_Render.o World_Map.o Main

## rule to compile .cpp to .o

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $<
