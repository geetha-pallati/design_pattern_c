CC = gcc
TARGET = adapter_pattern
CFLAGS = -Wall -Wextra
SRCS = state_pattern.c
OBJS = $(SRCS:.C=.o)
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)