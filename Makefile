CC=gcc
TARGET=myos
C_FILES=./console.c ./kernel.c
PROGRAM = Assignment1
SOURCES = console.c console.h kernel.c
OBJECTS = $(C_FILES:.c=.o)
CFLAGS = -o

.SUFFIXES:
.SIFFIXES: .c .o

.c.o : ; cc $(CFLAGS) -c $<

$(PROGRAM) : $(OBJECTS)
	cc -o $@ $(CFLAGS) $(OBJECTS)

clean : ; /bin/rm -f $(PROGRAM) $(OBJECTS)

depend: $(SOURCES)
	@ echo
	@ echo "Ignore warnings"
	@ echo
	makedepend $(INCLUDE) $(SOURCES)
