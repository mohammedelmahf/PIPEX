/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:44:19 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/01 14:44:58 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_path_access(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
		return (1);
	return (0);
}

char	**get_paths(char **env)
{
	while (*env && ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	if (!*env)
		return (NULL);
	return (ft_split(*env + 5, ':'));
}

char	*join_cmd_path(char *path, char *cmd)
{
	char	*cmd_path;

	cmd_path = malloc(ft_strlen(path) + ft_strlen(cmd) + 2);
	if (!cmd_path)
		return (NULL);
	ft_strcpy(cmd_path, path);
	ft_strcat(cmd_path, "/");
	ft_strcat(cmd_path, cmd);
	return (cmd_path);
}

char	*find_path(char *cmd, char **env)
{
	char	**paths;
	char	*cmd_path;
	int		i;

	if (check_path_access(cmd))
		return (ft_strdup(cmd));
	paths = get_paths(env);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		cmd_path = join_cmd_path(paths[i], cmd);
		if (cmd_path && check_path_access(cmd_path))
		{
			free_split(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_split(paths);
	return (NULL);
}

void	free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
