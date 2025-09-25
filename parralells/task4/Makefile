TARGET = rr
CC = g++
SRCS_DIR = src/
OBJECTS_DIR = build/
#CFLAGS = -g -O0
CFLAGS = -g -O0
SRCS = $(wildcard $(SRCS_DIR)*.cpp)
OBJECTS = $(patsubst $(SRCS_DIR)%.c, $(OBJECTS_DIR)%.o, $(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) main.cpp -o $(TARGET)
%.o: %.cpp
	$(CC) $< -c $@
clean:
	rm -rf $(OBJECTS_DIR)*.o $(TARGET)

