/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:46:51 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/21 23:42:45 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// char	*find_path(char *cmd, char **envp)
// {
// 	char	**paths;
// 	char	*path;
// 	int		i;
// 	char	*part_path;

// 	i = 0;
// 	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
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

char *find_path(char *cmd, char **envp)
{
    char    **paths;
    char    *path;
    int     i;
    char    *part_path;

    i = 0;
    while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
        i++;

    paths = ft_split(envp[i] + 5, ':');
    i = 0;
    while (paths[i])
    {
        part_path = ft_strjoin(paths[i], "/");
        path = ft_strjoin(part_path, cmd);
        free(part_path);
        if (access(path, F_OK) == 0)
        {
            // Add debug print
            write(2, "Found path: ", 11);
            write(2, path, ft_strlen(path));
            write(2, "\n", 1);
            
            int j = 0;
            while (paths[j])
                free(paths[j++]);
            free(paths);
            return (path);
        }
        free(path);
        i++;
    }

    i = 0;
    while (paths[i])
        free(paths[i++]);
    free(paths);
    return (0);
}

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void execute(char *argv, char **env)
{
    char    **cmd;
    int     i;
    char    *path;

    write(2, "Executing: ", 10);
    write(2, argv, ft_strlen(argv));
    write(2, "\n", 1);

    cmd = ft_split(argv, ' ');
    path = find_path(cmd[0], env);
    if (!path)
    {
        write(2, "Path not found for: ", 19);
        write(2, cmd[0], ft_strlen(cmd[0]));
        write(2, "\n", 1);
        while (cmd[++i])
            free(cmd[i]);
        free(cmd);
        error();
    }

    // Print execve arguments
    write(2, "Execve path: ", 12);
    write(2, path, ft_strlen(path));
    write(2, "\n", 1);

    if (execve(path, cmd, env) == -1)
    {
        perror("Execve failed");
        free(path);
        i = -1;
        while (cmd[++i])
            free(cmd[i]);
        free(cmd);
        error();
    }
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
// 		error();
// }

