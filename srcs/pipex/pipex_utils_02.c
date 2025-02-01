/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:47:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/01 14:34:25 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int fd1, int fd2)
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
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

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0 && s)
		write(fd, s, ft_strlen(s));
}
