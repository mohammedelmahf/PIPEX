/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:47:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/28 14:47:16 by maelmahf         ###   ########.fr       */
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

char	*cat_string(char *dst, const char *src)
{
	size_t	i;
	size_t	len_dst;

	if (!dst || !src)
		return (NULL);
	len_dst = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (dst);
}


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (1);
	if (s1[i] == '\n' && s2[i] == '\0')
		return (1);
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	n;

	n = 5;
	i = ft_strcmp("here_doc", argv[1]);
	if (i == 1)
		n = 6;
	if (argc < n)
	{
		write(2, "Invalid number of arguments\n", 28);
		exit(3);
	}
	if (i == 1)
		return (3);
	return (2);
}
