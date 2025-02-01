/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:58:17 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/31 19:18:32 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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



int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*ss1;
	unsigned char	*ss2;

	index = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (*ss1 && *ss2 && *ss1 == *ss2 && index < n)
	{
		ss1++;
		ss2++;
		index++;
	}
	if (index == n)
		return (0);
	return (*ss1 - *ss2);
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


char *ft_strcat(char *dst, const char *src)
{
    size_t i = 0;
    size_t len_dst = ft_strlen(dst);

    if (!dst || !src)
        return (NULL);
    while (src[i])
    {
        dst[len_dst + i] = src[i];
        i++;
    }
    dst[len_dst + i] = '\0';
    return (dst);
}
