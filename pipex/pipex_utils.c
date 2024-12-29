/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:46:51 by maelmahf          #+#    #+#             */
/*   Updated: 2024/12/28 21:38:32 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    error(void)
{
    perror("\033[31mError");
    exit(EXIT_FAILURE);
}

void    execute(char **argv , char **env)
{
    char    **cmd;
    int     i;
    char *path;

    i = -1;
    cmd = ft_split(argv, ' ');
    path = find_path(cmd[0] , env);
    if(!path)
    {
        while(cmd[++i])
            free(cmd[i]);
        free(cmd);
        error();
    }
    if(execve(path,cmd,env) == -1)
        error();

}