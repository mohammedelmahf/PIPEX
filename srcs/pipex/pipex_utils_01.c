/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:46:51 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/30 17:11:10 b
y maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_path(char *cmd, char **env)
{
    char *cmd_path;
    char *path_env;
    char **paths;
    int i;

    if (access(cmd, F_OK | X_OK) == 0)
        return (ft_strdup(cmd));
    while (*env && ft_strncmp(*env, "PATH=", 5) != 0)
        env++;
    if (!*env)
        return (NULL);
    path_env = *env + 5;
    paths = ft_split(path_env, ':');
    if (!paths)
        return (NULL);
    i = 0;
    while (paths[i])
    {
        cmd_path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
        if (!cmd_path)
            break;
        ft_strcpy(cmd_path, paths[i]);
        ft_strcat(cmd_path, "/");
        ft_strcat(cmd_path, cmd);
        if (access(cmd_path, F_OK | X_OK) == 0)
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

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
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

int	ft_word_count(const char *str, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*res;

	res = (char *)malloc(sizeof(char) + (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
