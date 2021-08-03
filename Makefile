NAME  = libftprintf.a

								#Project files
SRC_DIR := src
OBJ_DIR := build
SRCS = ft_printf.c
LIB = libs/libft/libft.a

HEADER_FILES = include/ft_printf.h
OBJS = $(SRCS:.c=.o)

								#Compiler flags
CC     = gcc
CFLAGS = -Wall -Wextra -Werror

								#Release build settings
RELDIR = .

RELEXE = $(RELDIR)/$(NAME)
RELOBJS = $(addprefix $(OBJ_DIR)/, $(OBJS))

								#Debug settings
ifdef DEBUG
CFLAGS	+=	-g
NAME = debug_libftprintf.a
endif
ifdef FSAN
CFLAGS	+=	-fsanitize=address
endif
ifdef SPEED
CFLAGS	+=	-Ofast
endif
ifdef ERROR
CFLAGS	+=	-D ELABORATE_ERR=1
endif
ifdef LEAKS
CFLAGS	+=	-D LEAKS=1
endif
								#Release rules
all: libft release

release: $(RELEXE)

$(RELEXE): $(RELOBJS) $(LIB)
	ar rcs $@ $^
	ar -q $(LIB) $(OBJ)
	cp $(LIB) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -o $@ $<

libft:
	$(MAKE) -C libs/libft/

clean:
	rm -f $(RELOBJS)
	$(MAKE) clean -C libs/libft/

fclean:
	rm -f $(RELEXE) $(RELOBJS) $(NAME)
	$(MAKE) fclean -C libs/libft/

re: fclean all

.PHONY: all clean release re fclean
