CXX=g++
EXEC:=$(shell basename "`pwd`" | sed 's/ /_/g')
SRCS:=$(shell find *.cpp)
OBJS:= $(SRCS:%.cpp=%.o)

all: $(EXEC)

full: clean all

%.o : %.cpp
	$(CXX) -c $< 
	
$(EXEC): $(OBJS)
	$(CXX) -o $@ $^ 
	
clean:
	rm *.o $(EXEC) -f