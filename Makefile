# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: safoh <safoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/11 14:27:07 by safoh         #+#    #+#                  #
#    Updated: 2021/08/12 15:41:01 by safoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			:=	libftprintf.a
CC				:=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				:=	rm -f

#################################Project_files##################################
# SRCS			=	RESOURCES
# SRC_DIR		=	SOURCES DIRECTORY
# INC_DIR		=	INCLUDES DIRECTORY
# BUILD_DIR		=	BUILD DIRECTORY
# OBJS			=	OBJECTS
# LIB			=	LIBFT LIBRARY

SRCS			:=	ft_printf.c
SRC_DIR			:=	./src
INC_DIR			:=	./include
BUILD_DIR		:=	./build
OBJS			:=	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
LIB				:=	libs/libft/libft.a

###############################################################################
# MESSSAGE		=	Message after compiling
# C_MESSAGE		=	Message for building objects

MESSSAGE		=	"Run "make ft_printf_test" to test the lilbftprintf.a"
C_MESSAGE		=	"Building C objects... %-33.33s\r"

#################################Debug_settings################################
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
ifdef CRITERION
CFLAGS	+=	-lcriterion
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@echo "\n"
	ar rcs $@ $^
	ar -q $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	@echo $(MESSSAGE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	@printf $(C_MESSAGE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -C libs/libft/

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libs/libft/
	@echo "Objects libft cleaned"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libs/libft/
	@echo "Library printf cleaned"

re: fclean all

ft_printf_test: all
	$(MAKE) quiet -C test/ft_printf_test/

ft_printf_tester: all
	cd test/ft_printf_tester; sh test m

.PHONY: all clean fclean ft_printf_test
