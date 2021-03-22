#Makefile
#Sam Rind
#CS300 Fall 2020
#Conways Game of Life

CPP = g++
CPPFLAGS = -Wall -g -Werror
TARGET = conway
SRCS = conway.cpp

$(TARGET): $(SRCS)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(SRCS) -lncurses

clean:
	-rm -f $(TARGET)
