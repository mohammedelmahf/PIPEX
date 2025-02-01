/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:46:26 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/31 19:04:28 by maelmahf         ###   ########.fr       */
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
