CC = gcc
CFLAGS =
LDFLAGS = 
OBJFILES = proj3_main.o DLList.o 
TARGET = proj3

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~