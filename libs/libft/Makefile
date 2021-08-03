NAME  = libft.a

								#Project files
SRC_DIR := src
OBJ_DIR := build
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c  ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		ft_tolower.c  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c  \
		ft_strdup.c ft_substr.c ft_strjoin.c  ft_strtrim.c ft_split.c  \
		ft_putnbr_fd.c ft_calloc.c ft_memchr.c ft_strmapi.c ft_itoa.c \

HEADER_FILES = libft.h
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
NAME = debug_libft.a
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
all: release

release: $(RELEXE)

$(RELEXE): $(RELOBJS) | $(RELDIR)
	ar rc $(RELEXE) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(RELOBJS)

fclean:
	rm -f $(RELEXE) $(RELOBJS) $(NAME)

re: fclean all

.PHONY: all clean release re debug fclean
