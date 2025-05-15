SRCS    := main.cpp io.cpp flower.cpp
HEADERS := sorts.h io.h flower.h
OBJS    := $(SRCS:.cpp=.o)

TARGET := FirstLab

all: $(TARGET)

$(TARGET) : $(OBJS)
	g++ $(OBJS) -o $(TARGET)

%.o : %.cpp
	g++ -c $< -o $@

clean :
	rm -f $(TARGET) *.o