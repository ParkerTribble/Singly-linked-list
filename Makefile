CC = gcc
CFLAGS =
LDFLAGS = 
OBJFILES = lab7_llist.o lab7_functions.o 
TARGET = lab7

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~