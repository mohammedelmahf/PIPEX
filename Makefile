NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra -g3 -fsanitize=address

RM = rm -rf

SRCS = 	srcs/pipex/pipex.c \
		srcs/pipex/pipex_utils_01.c \
		srcs/pipex/pipex_utils_02.c	\
		libft/libft.a

SRCS_BONUS = 	srcs/pipex_bonus/pipex_bonus.c \
				srcs/pipex_bonus/pipex_utils_bonus.c \
				libft/libft.a \
				libft/get_next_line/get_next_line.c \
				libft/get_next_line/get_next_line_utils.c

$(NAME) :
	make all -C libft	
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus : clean
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)