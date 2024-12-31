/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:46:51 by maelmahf          #+#    #+#             */
/*   Updated: 2024/12/31 16:48:56 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    find_path(char *cmd, char **env)
{
    int     i;
    char    *path;
    char    **paths;
    
    i = 0;
    while(ft_strnstr(env[i] ,"PATH" , 4) == 0)
        i++;
    paths = ft_split(env[i] + 5 , ':');
    i = 0;
}

void    error(void)
{
    perror("Error");
    exit(EXIT_FAILURE);
}

void    execute(char **argv , char **env)
{
    char    **cmd;
    int     i;
    char    *path;

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