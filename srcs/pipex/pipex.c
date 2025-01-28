/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:17:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/28 16:08:36 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	processes_pipex(int filein, char *cmd, int fileout)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		if (dup2(filein, 0) == -1)
			error();
		if (dup2(fileout, 1) == -1)
			error();
		execute(cmd);
		exit(7);
	}
	else
		wait(NULL);
}

void	create_processes(int argc, char **argv, int i)
{
	int	filein;
	int	fileout;
	int	pipe_fd[2];

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		error();
	while (i < argc - 2)
	{
		if (pipe(pipe_fd) == -1)
			error();
		processes_pipex(filein, argv[i], pipe_fd[1]);
		close(pipe_fd[1]);
		filein = pipe_fd[0];
		i++;
	}
	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	processes_pipex(filein, argv[i], fileout);
	close_fd(filein, fileout);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	int		i;

	i = check_args(argc, argv);
	check_env(argc, argv, env, i);
	if (argc != 5)
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		return (1);
	}
	if (pipe(fd) == -1)
		error();
	i = 2;
	create_processes(argc, argv, i);
	return (0);
}
