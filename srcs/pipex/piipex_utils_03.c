/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piipex_utils_03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:34:17 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/01 14:35:00 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
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

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
