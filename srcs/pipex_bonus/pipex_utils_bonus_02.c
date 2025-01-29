/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus_02.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:54:34 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/29 16:05:44 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int	open_file(char *file, int in_or_out, int tmp)
{
	int	fd;

	if (in_or_out == 0)
		fd = open(file, O_RDONLY);
	else if (in_or_out == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (in_or_out == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		if (tmp != -1)
			close(tmp);
		error();
	}
	return (fd);
}
