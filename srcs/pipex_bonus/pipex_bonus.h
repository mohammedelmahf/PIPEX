/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:01:50 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/30 17:18:27 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 1

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
void	ft_putstr_fd(char *s, int fd);

// Utility functions
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	**ft_split2(char **res, const char *s, char c);
void	*ft_free(char **str, int count);
int		ft_word_count(const char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *str, char c);
int		open_file(char *file, int in_or_out, int tmp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
