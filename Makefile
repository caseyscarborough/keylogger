all: keylogger.cpp keylogger.h
	g++ keylogger.cpp -framework ApplicationServices -framework Carbon -o keylogger

install:
	cp keylogger /usr/local/bin

clean:
	rm keylogger keystroke.log