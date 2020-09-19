# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gartaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/15 16:17:02 by gartaud           #+#    #+#              #
#    Updated: 2020/09/15 18:53:44 by gartaud          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

EXEC = ft_cat
LIBNAME = includes/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINKER_FLAGS = -Llibft
SRCSDIR = srcs/
DEPSDIR = includes/
DEPS = $(addprefix $(DEPSDIR),\
	   ft.h)
LIBFILES = $(addprefix $(SRCSDIR),\
		ft_putchar.c \
		ft_putstr.c \
		ft_atoi.c \
		ft_init.c \
		ft_obvious_case.c \
		ft_solve.c)
LIBOBJ = $(LIBFILES:%.c=%.o)
FILES = $(addprefix $(SRCSDIR),\
		main.c)
OBJ = $(FILES:%.c=%.o)

all: $(LIBNAME) $(EXEC)

# ======= LIBRARY =======

$(LIBNAME): $(LIBOBJ)
	ar rcs $@ $(LIBOBJ)

$(addprefix $(SRCSDIR), LIBOBJ): $(LIBFILES) $(DEPS)
	$(CC) $(CFLAGS) $(LIBFILES)

# ======= EXECUTABLE ========

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBNAME)

$(addprefix $(SRCSDIR), OBJ): $(FILES) $(DEPS)
	$(CC) $(CFLAGS) $(FILES)

clean:
	rm -f $(SRCSDIR)*.o

fclean: clean
	rm -f $(EXEC)
	rm -f $(LIBNAME)

re: fclean all
