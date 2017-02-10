CC = gcc
CFLAGS = -g -O0 -Wall
LIBS = -lm

SRCDIR = ./src
INCLUDES = -I${SRCDIR}/include

SRCS_ = main.c\
	read_fert.c\
	read_func.c\
	read_mgt.c\
	read_plant.c\
	read_till.c\
	sllist.c\
	sort_mgt.c\
	write_crop.c\
	write_op.c

HEADERS_ = swat2cycles.h\
	sllist.h

EXECUTABLE = swat2cycles

SRCS = $(patsubst %,$(SRCDIR)/%,$(SRCS_))
HEADERS = $(patsubst %,$(SRCDIR)/include/%,$(HEADERS_))
OBJS = $(SRCS:.c=.o)

.PHONY: clean

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(EXECUTABLE) $(OBJS) $(LIBS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo
	@echo "... Cleaning ..."
	@echo
	@$(RM) $(OBJS) $(EXECUTABLE)
