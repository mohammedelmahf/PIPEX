/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:42:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/01 15:00:14 by maelmahf         ###   ########.fr       */
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
			error_exit("Error reading line");
		if (ft_strncmp(line, stop, ft_strlen(stop)) == 0
			&& line[ft_strlen(stop)] == '\n')
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
}

void	processes_pipex(int filein, char *cmd, int fileout, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("pid failed");
	if (pid == 0)
	{
		if (dup2(filein, 0) == -1)
			error_exit("dup2 failed");
		if (dup2(fileout, 1) == -1)
			error_exit("dup2 failed");
		execute(cmd, env);
		exit(7);
	}
}

void	create_processes(int argc, char **argv, int i, char **env)
{
	int		filein;
	int		fileout;
	int		pipe_fd[2];

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		error_exit("File error");
	while (i < argc - 2)
	{
		if (pipe(pipe_fd) == -1)
			error_exit("Pipe failed");
		processes_pipex(filein, argv[i], pipe_fd[1], env);
		close(pipe_fd[1]);
		close(filein);
		filein = pipe_fd[0];
		i++;
	}
	fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error_exit("Output file error");
	processes_pipex(filein, argv[i], fileout, env);
	close_fd(filein, fileout);
}

void	execute(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = find_path(args[0], env);
	if (!args || !path)
	{
		free_split(args);
		error_exit("Command not found");
	}
	execve(path, args, env);
	free(path);
	free_split(args);
	error_exit("Execution failed");
}

int	main(int argc, char **argv, char **env)
{
	int	fd_in;
	int	i;

	i = check_args(argc, argv);
	check_env(argc, argv, env, i);
	if (i == 3)
	{
		fd_in = open_file(2, argv[1], -1);
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
	create_processes(argc, argv, i, env);
	exit(0);
}
