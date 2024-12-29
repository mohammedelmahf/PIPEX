/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:43:19 by maelmahf          #+#    #+#             */
/*   Updated: 2024/12/28 21:39:28 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <sys/types.h>
#include<unistd.h>
# include "../libft/libft.h"
void    error(void);
void    child_proc(char **argv, char **env, int *fd);
void    parent_proc(char **argv, char **env, int *fd);
void    execute(char **argv , char **env);
#endif