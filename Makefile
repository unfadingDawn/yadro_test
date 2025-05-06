TARGET = rr
CC = g++
SRCS = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SRCS))
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(MAIN_FILE) -o $(TARGET)
%.o: %.cpp
	$(CC) $< -c $@
%.o: %.c
	$(CC) $< -c $@
clean:
	rm -r *.o $(TARGET)
