/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:46:51 by maelmahf          #+#    #+#             */
/*   Updated: 2024/12/31 21:12:06 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;
	int		j;

	if (!cmd || !*cmd)
		return (NULL);
	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		if (part_path)
		{
			path = ft_strjoin(part_path, cmd);
			free(part_path);
			if (path && access(path, F_OK | X_OK) == 0)
			{
				j = 0;
				while (paths[j])
					free(paths[j++]);
				free(paths);
				return (path);
			}
			if (path)
				free(path);
		}
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (NULL);
}
void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	execute(char *argv, char **env)
{
	char **cmd;
	int i;
	char *path;

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