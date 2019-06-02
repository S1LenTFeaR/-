PROG = Base
CC = gcc 
SRCS = main.c note.c izvlekaem.c Sort.c pomeshaem.c vivod.c
OBJS = $(SRCS:.c=.o) 
 
all: $(PROG) 
 
$(PROG): $(OBJS) 
	$(CC) -o $(PROG) $(OBJS) 
 
clean: 
	rm -f $(PROG) $(OBJS) 
 
.c.o : factorial.h ; $(CC) -c $*.c