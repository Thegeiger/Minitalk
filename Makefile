##
## Makefile for make in /home/geiger_a/Makefile
## 
## Made by anthony geiger
## Login   <geiger_a@epitech.net>
## 
## Started on  Sat Jan  3 12:39:16 2015 anthony geiger
## Last update Wed Feb 25 15:40:20 2015 anthony geiger
##

RM	= rm -f

DEBUG	= 0

VERIF	= 0

CC	= gcc

NAME_SERV	= server

NAME_CLIENT	= client

LIBMY   = lib/my/


SRCS_SERV	= main.c

SRCS_CLIENT	= main.c


SRCS_DIR_CLIENT	= src/client/

SRCS_DIR_SERV	= src/server/


SRCS_CLIENT	:= $(addprefix $(SRCS_DIR_CLIENT), $(SRCS_CLIENT))

SRCS_SERV	:= $(addprefix $(SRCS_DIR_SERV), $(SRCS_SERV))


OBJS_SERV	= $(SRCS_SERV:.c=.o)

OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)


CFLAGS  = -I./include/
CFLAGS  += -Wall -Wextra -W
CFLAGS  += -pedantic

LDFLAGS = -L./lib/
LDFLAGS += -lmy


ifeq ($(DEBUG), 1)
        CFLAGS  += -g -std=c99
        CC      := clang -Weverything
endif

ifeq ($(VERIF), 1)
        CFLAGS  += -g -std=c99
        LDFLAGS += -lstdc++
        CC      := gcc
endif


all: dependency $(NAME_CLIENT) $(NAME_SERV)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(OBJS_CLIENT) -o $(NAME_CLIENT) $(LDFLAGS)

$(NAME_SERV): $(OBJS_SERV)
	$(CC) $(OBJS_SERV) -o $(NAME_SERV) $(LDFLAGS)

dependency:
	make -C $(LIBMY)

docs:
	doxygen

re:	fclean all

clean:
	$(RM) $(OBJS_CLIENT)
	$(RM) $(OBJS_SERV)
	make -C $(LIBMY) clean

fclean: clean
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_SERV)
	make -C $(LIBMY) fclean

.PHONY: all clean fclean re dependency docs
