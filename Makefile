SOURCES = led.o morse.o parse.o main.o
HEADERS = led.h morse.h parse.h
CXXFLAGS = -I.
pish: $(SOURCES) $(HEADERS) Makefile
	g++ $(SOURCES) -o pish
all: pish
clean:
	rm -f *~
	rm -f *.o
	rm -f pish
install: pish
	cp pish /bin
