# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 14:32:10 by maelmahf          #+#    #+#              #
#    Updated: 2025/02/01 15:05:29 by maelmahf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/pipex/pipex.c \
		srcs/pipex/pipex_utils_01.c \
		srcs/pipex/pipex_utils_02.c \
		srcs/pipex/pipex_utils_03.c \
		srcs/pipex/pipex_utils_04.c \

SRCS_BONUS = 	srcs/pipex_bonus/pipex_bonus.c \
				srcs/pipex_bonus/pipex_bonus_utils_01.c \
				srcs/pipex_bonus/pipex_bonus_utils_02.c \
				srcs/pipex_bonus/pipex_bonus_utils_03.c \
				srcs/pipex_bonus/pipex_bonus_utils_04.c \
				srcs/pipex_bonus/pipex_bonus_utils_05.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(OBJS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus : clean
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)