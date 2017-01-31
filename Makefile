CC = gcc
CFLAGS = -g -O0 -Wall

SRCDIR = ./src
LIBS = -lm
INCLUDES = -I${SRCDIR}/include

SRCS_ = main.c\
	read_mgt.c\
	read_func.c\
	sllist.c\
	sort_mgt.c

HEADERS_ = swat2cycles.h\
	sslist.h	

EXECUTABLE = swat2cycles


SRCS = $(patsubst %,$(SRCDIR)/%,$(SRCS_))
HEADERS = $(patsubst %,$(SRCDIR)/include/%,$(HEADERS_))

OBJS = $(SRCS:.c=.o)

.PHONY: all clean help

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(EXECUTABLE) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS) $(EXECUTABLE)
