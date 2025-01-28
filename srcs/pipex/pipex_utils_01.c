/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:46:51 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/28 16:06:30 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_env(int ac, char **av, char **env, int i)
{
	if (*env != NULL)
		return ;
	while (i < ac - 1)
	{
		write(2, "Command not found: ", 19);
		write(2, av[i], ft_strlen(av[i]));
		write(2, "\n", 1);
		i++;
	}
	exit(2);
}

char	*find_path(char *cmd)
{
	char	*cmd_path;

	cmd_path = malloc(ft_strlen("/usr/bin/") + ft_strlen(cmd) + 1);
	if (!cmd_path)
		error();
	cmd_path[0] = '\0';
	cat_string(cmd_path, "/usr/bin/");
	cat_string(cmd_path, cmd);
	if (access(cmd_path, F_OK | X_OK) == 0)
		return (cmd_path);
	free(cmd_path);
	return (NULL);
}

void	execute(char *cmd)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args)
		error();
	path = find_path(args[0]);
	if (!path)
	{
		free_split(args);
		error();
	}
	if (execve(path, args, NULL) == -1)
	{
		free(path);
		free_split(args);
		error();
	}
}

void	error(void)
{
	perror("Error");
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
