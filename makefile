# output name
TARGET	=	BuyTickets

# compiler
CC	=	gcc

# debug
DEBUG	=	-g

# optimisation
OPT	=	-O0

# warnings
WARN	=	-Wall

PTHREAD	=	-pthread

CCFLAGS	=	$(DEBUG)	$(OPT)	$(WARN)	$(PTHREAD)	-pipe

GTKLIB	=	`pkg-config	--cflags	--libs	gtk+-3.0`

# linker
LD	=	gcc
LDFLAGS	=	$(PTHREAD)	$(GTKLIB)	$(WARN)	-Wl,--export-all-symbols

OBJS	=    out/main.o	out/signals.o	out/misc.o

all:	$(OBJS)
	$(LD)	-o	$(TARGET)	$(OBJS)	$(LDFLAGS)

out/main.o:	source/main.c
	$(CC)	-c	$(CCFLAGS)	source/main.c	$(GTKLIB)	-o out/main.o

out/signals.o:	source/signals.c
	$(CC)	-c	$(CCFLAGS)	source/signals.c	$(GTKLIB)	-o out/signals.o

out/misc.o:	source/misc.c
	$(CC)	-c	$(CCFLAGS)	source/misc.c	$(GTKLIB)	-o	out/misc.o

clean:
	rm	-f	*.o	$(TARGET)
