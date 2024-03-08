# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:30:34 by kbrauer           #+#    #+#              #
#    Updated: 2023/12/09 15:39:56 by kbrauer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./code
PRINTF_DIR = ./code/printf
LIBFT_DIR = ./code/libft_bonus
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(SRCS_DIR)/define_costs.c \
		$(SRCS_DIR)/define_targets.c \
		$(SRCS_DIR)/find_targets.c \
		$(SRCS_DIR)/ftsio.c \
		$(SRCS_DIR)/get_nodes_to_top_2.c \
		$(SRCS_DIR)/get_nodes_to_top.c \
		$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/push.c \
		$(SRCS_DIR)/reverse_rotate.c \
		$(SRCS_DIR)/rotate.c \
		$(SRCS_DIR)/sort_4+.c \
		$(SRCS_DIR)/sort.c \
		$(SRCS_DIR)/swap.c \
		$(SRCS_DIR)/utils.c
	
OBJS = $(SRCS:.c=.o)

.c.o:
	cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(PRINTF) $(LIBFT) $(OBJS)
		cc  $(LFLAGS) -o $@ $(OBJS) -L. ./code/printf/libftprintf.a ./code/libft_bonus/libft.a

$(LIBFT):
		make -C $(LIBFT_DIR) all
		
$(PRINTF):
		make -C $(PRINTF_DIR) all

all: $(NAME)

clean:
	rm -f $(OBJS) $(PRINTF_DIR)/*.o $(LIBFT_DIR)/*.o

fclean: clean
	rm -f $(NAME) ./code/printf/libftprintf.a ./code/libft_bonus/libft.a

re: fclean all

.PHONY: all, clean, fclean, re
