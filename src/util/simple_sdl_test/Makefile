##
## Makefile
##  
## Made by Jonathan Rowlands
## Login   <jonathancacodemon>
##
## Started on  Mon Jun  1 14:52:57 2009 Jonathan Rowlands
## Last update Mon Jun  1 14:52:57 2009 Jonathan Rowlands
## 
##############################
# Complete this to make it ! #
##############################
NAME 	= simple_sdl_test		# Name of executable file
SRC	= simple_sdl_test.c		# List of *.c
INCL  	=		# List of *.h
################
# Optional add #
################
IPATH   = -I.           # path of include file
OBJOPT  = -O2 -Wall -Wstrict-prototypes       # option for obj
EXEOPT  = -O2 -Wall -Wstrict-prototypes       # option for exe (-lefence ...)
LPATH   = -L.           # path for librairies ... 

#####################
# Macro Definitions #
#####################
CC 	= cc
MAKE 	= make
SHELL	= /bin/sh
OBJS 	= $(SRC:.c=.o) 
RM 	= /bin/rm -f 	
COMP	= gzip -9v
UNCOMP	= gzip -df
STRIP	= strip

SDL_CFLAGS = $(shell sdl-config --cflags)
SDL_LDFLAGS = $(shell sdl-config --libs)
CFLAGS  = $(OBJOPT) $(IPATH) $(SDL_CFLAGS)
LDFLAGS = $(EXEOPT) $(LPATH) $(SDL_LDFLAGS)

.SUFFIXES: .h.Z .c.Z .h.gz .c.gz .c.z .h.z 

##############################
# Basic Compile Instructions #
##############################

all:	$(NAME)
$(NAME): $(OBJS) $(SRC) $(INCL)  
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME) 
#	$(STRIP) ./$(NAME) # if you debug ,don't strip ...

depend:
	gcc $(IPATH) -MM $(SRC) 
clean:
	-$(RM) $(NAME) $(OBJS) *~
fclean:
	-$(RM) $(NAME)
comp: clean
	$(COMP) $(INCL) $(SRC)
ucomp: 
	$(UNCOMP) $(SRC) $(INCL)

.c.Z.c .h.Z.h .c.gz.c .h.gz.h .c.z.c .h.z.h :
	 -$(UNCOMP) $<

.c.o:
	$(CC) $(CFLAGS) -c $< 
################
# Dependencies #
################
