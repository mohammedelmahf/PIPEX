/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:46:26 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/01 14:59:24 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
