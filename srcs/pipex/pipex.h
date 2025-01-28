/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:43:19 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/28 14:45:23 by maelmahf         ###   ########.fr       */
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


void    close_fd(int fd1, int fd2);
int	    ft_strcmp(char *s1, char *s2);
int	    check_args(int argc, char **argv);
void    free_split(char **array);
char	*cat_string(char *dst, const char *src);
void	execute(char *argv);
char	*find_path(char *cmd);
void	error(void);
void	create_processes(int argc ,char **argv, int i);
void	processes_pipex(int filein, char *cmd, int fileout);
void	check_env(int ac, char **av, char **env, int i);
#endif
