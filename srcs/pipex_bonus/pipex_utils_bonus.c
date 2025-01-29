/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:46:26 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/29 15:21:27 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int	open_file(char *file, int in_or_out , int tmp)
{
	int	fd;

	if (in_or_out == 0)
		fd = open(file, O_RDONLY);
	else if (in_or_out == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (in_or_out == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		if (tmp != -1)
			close(tmp);
		ft_msg_error("Error open file\n", NULL, 1);
	}
	return (fd);
}

// void	execute(char *argv, char **env)
// {
// 	char	**cmd;
// 	int		i;
// 	char	*path;

// 	i = -1;
// 	cmd = ft_split(argv, ' ');
// 	path = find_path(cmd[0], env);
// 	if (!path)
// 	{
// 		while (cmd[++i])
// 			free(cmd[i]);
// 		free(cmd);
// 		error();
// 	}
// 	if (execve(path, cmd, env) == -1)
// 	{
// 		while (cmd[++i])
// 			free(cmd[i]);
// 		free(cmd);
// 		error();
// 	}
// }

// void	handle_here_doc(char **av, int *fd_out)
// {
// 	*fd_out = open_file(av[4], 2);
// 	here_doc(av);
// }

// char	*find_path(char *cmd, char **envp)
// {
// 	char	**paths;
// 	char	*path;
// 	int		i;
// 	char	*part_path;

// 	i = 0;
// 	while (ft_strnstr(envp[i], "PATH", 4) == 0)
// 		i++;
// 	paths = ft_split(envp[i] + 5, ':');
// 	i = 0;
// 	while (paths[i])
// 	{
// 		part_path = ft_strjoin(paths[i], "/");
// 		path = ft_strjoin(part_path, cmd);
// 		free(part_path);
// 		if (access(path, F_OK) == 0)
// 			return (path);
// 		free(path);
// 		i++;
// 	}
// 	i = -1;
// 	while (paths[++i])
// 		free(paths[i]);
// 	free(paths);
// 	return (0);
// }



int	check_args(int argc, char **argv)
{
	int	expected_args;
	int	is_here_doc;

	if (argc < 2)
	{
		write(2, "Invalid number of arguments\n", 28);
		exit(3);
	}

	is_here_doc = 0;
	if (ft_strcmp("here_doc", argv[1]) == 0)
		is_here_doc = 1;

	expected_args = 5;
	if (is_here_doc)
		expected_args = 6;

	if (argc < expected_args)
	{
		write(2, "Invalid number of arguments\n", 28);
		exit(3);
	}

	if (is_here_doc)
		return (3);
	return (2);
}