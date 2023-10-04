SOURCES = main.cpp part1.cpp part2.cpp
OBJECTS = ${SOURCES:.cpp=.o}
EXECUTABLE = executable
CXX = g++
#CXXFLAGS = -g -Wall -pedantic -Wextra -I.

#This is a makefile without explicit pattern matching
#GNU Make tool provides implicit pattern matching rules 
#Does not consider changes in the header files
all: ${EXECUTABLE}

${EXECUTABLE}: ${OBJECTS}
	${CXX} -o $@ $^

clean: 
	rm -f *.o ${EXECUTABLE} 
