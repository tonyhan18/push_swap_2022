# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 20:53:45 by chahan            #+#    #+#              #
#    Updated: 2022/04/10 18:38:33 by chahan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rc

SRCS_DIR =	./srcs				\
			./srcs/instructions	\
			./srcs/settings	\
			./srcs/sorting

OBJS_DIR = ./objs
INC_DIR = ./includes

LIBFT = libft.a
LIBFT_DIR = ./libft

SRCS =	./srcs/main.c			\
		./srcs/sorting/push_swap_utils.c \
		./srcs/instructions/error.c				\
		./srcs/instructions/free.c				\
		./srcs/instructions/get_value.c	\
		./srcs/instructions/push.c			\
		./srcs/instructions/reverse_rotate.c	\
		./srcs/instructions/swap.c			\
		./srcs/instructions/rotate.c			\
		./srcs/settings/check_arg.c	\
		./srcs/settings/ft_atoi.c	\
		./srcs/settings/make_stack.c\
		./srcs/sorting/handle_under_three.c	\
		./srcs/sorting/sort_more_a_to_b.c			\
		./srcs/sorting/sort_five.c			\
		./srcs/sorting/sort_three_a.c		\
		./srcs/sorting/sort_three_b.c		\
		./srcs/sorting/sort_more_b_to_a.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INC_DIR) -I$(LIBFT_DIR) -c $^

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)
	@if [ -f ./checker ]; then $(RM) ./checker; fi;

re : fclean all