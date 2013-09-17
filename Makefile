CC=g++
CFLAGS=-framework ApplicationServices -framework Carbon
SOURCES=keylogger.cpp keylogger.h
EXECUTABLE=keylogger
INSTALLDIR=/usr/local/bin

all: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXECUTABLE)

install:
	cp $(EXECUTABLE) $(INSTALLDIR)

uninstall:
	rm $(INSTALLDIR)/$(EXECUTABLE)

clean:
	rm $(EXECUTABLE)