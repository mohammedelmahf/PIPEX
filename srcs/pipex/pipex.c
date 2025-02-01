/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:17:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/01 14:38:23 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	check_env(int argc, char **argv, char **env, int i)
{
	if (*env != NULL)
		return ;
	while (i < argc - 1)
	{
		write(2, "Command not found: ", 19);
		write(2, argv[i], ft_strlen(argv[i]));
		write(2, "\n", 1);
		i++;
	}
	exit(2);
}

void	create_processes(int argc, char **argv, int i ,char **env)
{
	int	filein;
	int	fileout;
	int	pipe_fd[2];

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		error_exit("File error");
	while (i < argc - 2)
	{
		if (pipe(pipe_fd) == -1)
			error_exit("Pipe failed");
		processes_pipex(filein, argv[i], pipe_fd[1] , env);
		close(pipe_fd[1]);
		filein = pipe_fd[0];
		i++;
	}

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error_exit("Output file error");
	processes_pipex(filein, argv[i], fileout , env);
	close_fd(filein, fileout);
	while(wait(NULL) > 0)
	{
	}
}

void execute(char *cmd, char **env)
{
    char **args = ft_split(cmd, ' ');
    char *path = find_path(args[0], env);

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
		error_exit("pipe failed");
	i = 2;
	create_processes(argc, argv, i , env);
	return (0);
}