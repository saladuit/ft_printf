# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                        |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/07/16 23:01:02 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/07/16 23:01:29 by safoh        \___)=(___/                  #
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

SRCS			:=	ft_printf.c ft_printpct.c ft_printpnt.c ft_printhe_x.c \
		ft_printhex.c ft_printudec.c ft_printdec.c ft_printstr.c ft_cnvspc.c \
		ft_printchr.c
SRC_DIR			:=	./src
INC_DIR			:=	./include
BUILD_DIR		:=	./build
OBJS			:=	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
LIB				:=	libs/libft/libft.a

################################################################################
# MESSSAGE		=	Message after compiling
# C_MESSAGE		=	Message for building objects

MESSSAGE		=	"Run "make ft_printf_test" to test the lilbftprintf.a"
C_MESSAGE		=	"Building C objects... %-33.33s\r"

#################################Debug_settings#################################
ifdef DEBUG
CFLAGS	+=	-g
NAME = libftprintf_debug.a
LIB = libs/libft/libft_debug.a
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
	$(RM) $(NAME) printf_gdb
	$(MAKE) fclean -C libs/libft/
	rm -rf printf_gdb.dSYM
	@echo "Library printf cleaned"

re: fclean all

main:
	gcc src/main.c -L. -lftprintf_debug  -g -o printf_gdb

.PHONY: all clean fclean ft_printf_test fr_printf_tester main re
