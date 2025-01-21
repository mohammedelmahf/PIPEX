/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:43:19 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/21 23:11:20 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

void	error(void);
void	child_proc(char **argv, char **env, int *fd);
void	parent_proc(char **argv, char **env, int *fd);
void	execute(char *argv, char **env);
char	*find_path(char *cmd, char **envp);
void	free_split(char **split);
void	ft_free_tab(char **tab);



void	exec(char *cmd, char **env);
char	*get_path(char *cmd, char **env);
char	*my_getenv(char *name, char **env);
#endif
