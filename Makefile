NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra 

RM = rm -rf

SRCS = 	srcs/pipex/pipex.c\
		srcs/pipex/pipex_utils.c\
		libft/libft.a\

SRCS_BONUS = 	srcs/pipex_bonus/pipex_bonus.c\
				srcs/pipex_bonus/pipex_utils_bonus.c\
				libft/libft.a\

$(NAME) :
	make all -C libft	
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


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
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)