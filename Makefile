SOURCES = led.o morse.o main.o
HEADERS = led.h morse.h
CXXFLAGS = -I.
pish: $(SOURCES) $(HEADERS) Makefile
	g++ $(SOURCES) -o pish
all: pish
clean:
	rm -f *~
	rm -f *.o
	rm -f pish
