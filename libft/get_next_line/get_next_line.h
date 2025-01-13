/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:30:37 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/13 14:04:37 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

char				*get_next_line(int fd);
void				create_list(t_list **list, int fd);
void				add_node(t_list **list, char *buf);
char				*get_line(t_list *list);
void				copy_str(t_list *list, char *next_str);
int					len_to_newline(t_list *list);
int					found_line(t_list *list);
void				trim_word(char *dst, const char *src, size_t index);
int					check_node(char *s);
void				del_nodes(t_list **lst, size_t i);


#endif
