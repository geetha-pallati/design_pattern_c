CC = gcc
TARGET = adapter_pattern
CFLAGS = -Wall -Wextra 
SRCS = adapter_pattern.c 
OBJS = $(SRCS:.c=.o)	
all: $(TARGET)	
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)