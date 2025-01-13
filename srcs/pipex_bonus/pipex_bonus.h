/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:42:39 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/13 11:56:55 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_h
# define PIPEX_BONUS_h

# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void    here_doc(char **av);
int	    open_file(char *file , int in_or_out);
void    here_doc_put_in(char **av,int *fd);
void    pipe_do(char *av , char **env);
void	error(void);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **env);

#endif