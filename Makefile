LDIR =./lib
IDIR =./include
CC=gcc
CFLAGS= -g -Wall -I$(IDIR)

TARGET = main
OBJ = main.o 

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f *.o *~ $(INCDIR)/*~ $(TARGET)
