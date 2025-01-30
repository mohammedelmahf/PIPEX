/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:46:51 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/30 17:11:10 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
