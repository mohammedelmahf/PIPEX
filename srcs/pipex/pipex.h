/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:43:19 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/29 15:11:20 by maelmahf         ###   ########.fr       */
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

// File descriptor management
void	close_fd(int fd1, int fd2);

// Argument and string handling
int		ft_strcmp(const char *s1, const char *s2);
int		check_args(int argc, char **argv);
void	free_split(char **array);
char	*cat_string(char *dst, const char *src);

// Process and command execution
void	execute(char *argv);
char	*find_path(char *cmd);
void	error(void);
void	create_processes(int argc, char **argv, int i);
void	processes_pipex(int filein, char *cmd, int fileout);
void	check_env(int ac, char **av, char **env, int i);

#endif
