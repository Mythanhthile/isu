#variable
target=output
GCC=g++

#this is not a file
.PHONY = all

#recipe
all: ${target}

output: hello.cpp
	${GCC} -o hello hello.cpp


#call make clean to trigger command
clean: 
	rm -f *.o hello 


#The "output" target depends directly on the "hello.cpp" source file.
#The command for the "output" target links the "hello.cpp" source file directly into an executable named "hello" using the -o option.