/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:46:26 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/01 14:10:26 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

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

char *ft_strcpy(char *dst, const char *src)
{
    size_t i = 0;

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
