/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:42:39 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/29 15:47:53 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../../libft/libft.h"
# include "../../libft/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

void	close_fd(int fd1, int fd2);

// Argument and string handling
int		ft_strcmp(const char *s1, const char *s2);
int		check_args(int argc, char **argv);
void	free_split(char **array);
char	*cat_string(char *dst, const char *src);

// Process and command execution
int		open_file(char *file, int in_or_out , int tmp);
void	execute(char *argv);
char	*find_path(char *cmd);
void	error(void);
void	create_processes(int argc, char **argv, int i);
void	processes_pipex(int filein, char *cmd, int fileout);
void	check_env(int ac, char **av, char **env, int i);

void	ft_here_doc(char *stop, int fd);
#endif
