/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:47:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/30 16:15:00 by maelmahf         ###   ########.fr       */
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_split2(char **res, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	h;

	i = 0;
	h = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			res[h] = ft_substr(s, j, i - j);
			if (!res[h])
				return (ft_free(res, h));
			h++;
		}
	}
	res[h] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!res)
		return (NULL);
	return (ft_split2(res, s, c));
}

void	*ft_free(char **str, int count)
{
	while (count > 0)
	{
		free(str[count - 1]);
		count--;
	}
	free(str);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	size_t	s_len;
	char	*res;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		size = s_len - start;
	else
		size = len;
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
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