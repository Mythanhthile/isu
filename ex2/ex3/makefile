SOURCES=*.cpp
CXXFLAGS=-I.
#OBJECTS and DEPS variables will contain the full paths to the object 
#and dependency files with the specified build directory prefix.
OBJECTS=$(addprefix $(BUILD_DIR)/,$(SOURCES:.cpp=.o))
DEPS=$(addprefix $(BUILD_DIR)/,$(SOURCES:.cpp=.d))
#?= is default value if not set
ARCH ?=x86-64

# Making for x86 -64 e.g. x86 -64 (the architecture employed)
# > make ARCH=x86 -64
#sets the name and path of the executable (output) file to "bin/x86-64/prog_file" when building for "x86-64."
ifeq (${ARCH},x86-64)
CXX=g++
BUILD_DIR =build/x86-64
BIN_DIR=bin/x86-64
EXE=$(addprefix $(BIN_DIR)/,prog_file)
endif

# Making for architecture
# > make ARCH=arm
ifeq (${ARCH},arm)
CXX=arm-rpizw-g++
BUILD_DIR =build/arm
BIN_DIR=bin/arm
EXE=$(addprefix $(BIN_DIR)/,prog_file)
endif

$(EXE): $(DEPS) $(OBJECTS) # << Check the $(DEPS) new dependency
	$(CXX) $(CXXFLAGS ) -o $@ $(OBJECTS)

# %.cpp -> %.o needs to be added! Target is NOT just %.o...
$(BUILD_DIR)/%.o:%.cpp
	$(CXX) $^ -o $@ $(CXXFLAGS)

# Rule that describes how a .d (dependency) file is created from a .cpp file
# Similar to the assigment that you just completed %.cpp -> %.o
# generating dependency files (%.d) in the BUILD_DIR directory based on source files 
$(BUILD_DIR)/%.d: %.cpp
	$(CXX) -MT$@ -MM $(CXXFLAGS) $< > $@
	$(CXX) -MT$(@:.d=.o) -MM $(CXXFLAGS) $< >> $@
#-MM: instructs the compiler to generate dependency information in a makefile format.

#$<: This refers to the prerequisite, which is the source file (%.cpp) that you want to generate dependencies for.

#> $@: This redirects the output of a command to the file specified by $@, overwriting its content if the file already exists.

#>> $@: This appends the output of a command to the file specified by $@, preserving the existing content of the file and adding the new output at the en

# rule for making dir for generated files 
$(BUILD_DIR):
	mkdir -p $@

# rule for making dir for executable
$(BIN_DIR):
	mkdir -p $@

format: $(SOURCES:.cpp=.format)
%.format: %.cpp
	@echo "Formatting file '$<'"...
	@clang-format -i $<
	@echo "" > $@
	
#if makecmdgoals is not equal to clean
ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif
