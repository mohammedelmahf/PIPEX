/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:46:26 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/13 10:34:04 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int	open_file(char *file , int in_or_out)
{
	int fd;
	if(in_or_out == 0)
		fd = open(file , O_RDONLY , 0777);
	if(in_or_out == 1)
		fd = open(file , O_RDONLY | O_CREAT | O_TRUNC , 0777);
	if(in_or_out == 2)
		fd = open(file, O_RDONLY | O_CREAT | O_APPEND, 0777);
	if(fd == -1)
		error();
	return(fd);
		
}
void	execute(char *argv, char **env)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], env);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, env) == -1)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
}
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}
