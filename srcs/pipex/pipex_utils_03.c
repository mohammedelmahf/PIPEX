/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:58:17 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/30 17:16:18 by maelmahf         ###   ########.fr       */
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
