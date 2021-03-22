#Makefile
#Sam Rind
#CS300 Fall 2020
#ncurses

CPP = g++
CPPFLAGS = -Wall -g -Werror
TARGET = hello
SRCS = hello.cpp

$(TARGET): $(SRCS)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(SRCS) -lncurses

clean:
	-rm -f $(TARGET)
