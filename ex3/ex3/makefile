CXX=g++
CXXFLAGS=-Wall -pthread -I.
EXE=main
OBJECT=$(SOURCES:..c=.o)
SOURCES=main.cpp thread.cpp
DEPS=$(SOURCES:.cpp=.d)

.PHONY: all
all: $(EXE)

$(EXE): $(OBJECT)
	$(CXX) $(CXXFLAGS) $(OBJECT) -o $(EXE) 

%.o:%.cpp
	$(CXX) -o $@ -c $<


.PHONY: clean
clean:
	rm -f $(EXE) *.o


.PHONY: format
format:$(SOURCES:.cpp= .format)
%.format: %.cpp
	@echo "Formatting file '$<'"...
	@clang-format -i $<
	@echo "" > $@

.PHONY: tidy
tidy: $(SOURCES:.cpp=.tidy)
%.tidy: %.cpp
	@echo "Tidying file '$<'"...
	@clang-tidy $< -- $(CXXFLAGS)
	@echo "" > $@


.PHONY: help
help:
	@echo ./$(EXE)
	@echo make clean