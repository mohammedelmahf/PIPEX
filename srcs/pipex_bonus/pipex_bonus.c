/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:42:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/29 15:20:18 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	here_doc_put_in(char **av, int *fd)
// {
// 	char	*ret;

// 	close(fd[0]);
// 	while (1)
// 	{
// 		ret = get_next_line(0);
// 		if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0)
// 		{
// 			free(ret);
// 			exit(0);
// 		}
// 		ft_putstr_fd(ret, fd[1]);
// 		free(ret);
// 	}
// }

// void	here_doc(char **av)
// {
// 	int		fd[2];
// 	pid_t	pid;

// 	if (pipe(fd) == -1)
// 		error();
// 	pid = fork();
// 	if (pid == -1)
// 		error();
// 	if (pid == 0)
// 		here_doc_put_in(av, fd);
// 	else
// 	{
// 		close(fd[1]);
// 		dup2(fd[0], STDIN_FILENO);
// 		wait(NULL);
// 	}
// }

// void	pipe_do(char *cmd, char **env)
// {
// 	int		fd[2];
// 	pid_t	pid;

// 	if (pipe(fd) == -1)
// 		error();
// 	pid = fork();
// 	if (pid == -1)
// 		error();
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		execute(cmd, env);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		dup2(fd[0], STDIN_FILENO);
// 	}
// }

// int	is_here_doc(char **av)
// {
// 	if (ft_strncmp(av[1], "here_doc", 8) == 0)
// 		return (1);
// 	return (0);
// }

int	main(int ac, char **av, char **env)
{
	int	fd_in;
	int	i;

	i = ft_check_args(ac, av);
	ft_check_env(ac, av, env, i);
	if (i == 3)
	{
		fd_in = open_file( av[1] ,2, -1);
		ft_here_doc(av[2], fd_in);
		i = 2;
		while (i < ac - 1)
		{
			av[i] = av[i + 1];
			i++;
		}
		ac--;
	}
	i = 2;
	ft_main(ac, av, i);
	exit(0);
}