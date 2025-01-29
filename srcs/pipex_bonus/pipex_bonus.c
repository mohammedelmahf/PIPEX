/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:42:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/29 15:51:14 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_here_doc(char *stop, int fd)
{
	char	*line;

	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
		if (!line)
			error();

		if (ft_strncmp(line, stop, ft_strlen(stop)) == 0 && line[ft_strlen(stop)] == '\n')
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
}

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

// void	create_processes(int argc, char **argv, int i)
// {
// 	int	filein;
// 	int	fileout;
// 	int	pipe_fd[2];

// 	filein = open(argv[1], O_RDONLY);
// 	if (filein == -1)
// 		error();
// 	while (i < argc - 2)
// 	{
// 		if (pipe(pipe_fd) == -1)
// 			error();
// 		processes_pipex(filein, argv[i], pipe_fd[1]);
// 		close(pipe_fd[1]);
// 		filein = pipe_fd[0];
// 		i++;
// 	}
// 	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	if (fileout == -1)
// 		error();
// 	processes_pipex(filein, argv[i], fileout);
// 	close_fd(filein, fileout);
// }

void create_processes(int argc, char **argv, int i)
{
    int filein;
    int fileout;
    int pipe_fd[2];

    filein = open(argv[1], O_RDONLY);
    if (filein == -1)
        error();
    while (i < argc - 2)
    {
        if (pipe(pipe_fd) == -1)
            error();
        processes_pipex(filein, argv[i], pipe_fd[1]);
        close(pipe_fd[1]);
        close(filein);
        filein = pipe_fd[0];
        i++;
    }
    fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fileout == -1)
        error();
    processes_pipex(filein, argv[i], fileout);
    close_fd(filein, fileout);
}

int	main(int argc, char **argv, char **env)
{
	int	fd_in;
	int	i;

	i = check_args(argc, argv);
	check_env(argc, argv, env, i);
	if (i == 3)
	{
		fd_in = open_file( argv[1] ,2, -1);
		ft_here_doc(argv[2], fd_in);
		i = 2;
		while (i < argc - 1)
		{
			argv[i] = argv[i + 1];
			i++;
		}
		argc--;
	}
	i = 2;
	create_processes(argc , argv ,i);
	exit(0);
}