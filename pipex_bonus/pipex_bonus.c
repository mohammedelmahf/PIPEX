/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:42:04 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/13 11:19:32 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void    here_doc_put_in(char **av,int *fd)
{
    char *ret;
    
    close(fd[0]);
    while(1)
    {
        ret = get_next_line(0);
        if(ft_strncmp(ret, av[2] , ft_strlen(av[2])) == 0)
        {
            free(ret);
            exit(0);
        }
        ft_putstr_fd(ret, fd[1]);
        free(ret);
    }
}

void    here_doc(char **av)
{
    int fd[2];
    pid_t   pid;

    if(pipe(fd) == -1)
        error();
    pid = fork();
    if(pid == -1)
        error();
    if(!pid)
    {
        here_doc_put_in(av,fd);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0] ,STDIN_FILENO);
        wait(NULL);
    }
}

void    pipe_do(char *cmd , char **env)
{
    int fd[2];
    pid_t   pid;

    if(pipe(fd) == -1)
        error();
    pid = fork();
    if(pid ==  -1)
        error();
    if(!pid)
    {
        close(fd[0]);
        dup2(fd[1] , STDOUT_FILENO);
        execute(cmd , env);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0] , STDIN_FILENO);
    }
}

int main(int ac , char **av, char **env)
{
    int i;
    int fd_in;
    int fd_out;
    
    if(ac < 5)
        error();
    if(ft_strcmp(av[1], "here_doc") == 0)
    {
        if(ac < 6)
            error();
        i = 3;
        fd_out = open_file(av[ac - 1] , 2);
        here_doc(av);
    }
    else
    {
        i = 2; 
        fd_in = open_file(av[1] , 0);
        fd_out = open_file(av[ac -1] ,1);
        dup2(fd_in ,STDIN_FILENO);
    }
    while(i < ac - 2)
        pipe_do(av[i++] , env);
    dup2(fd_out , STDOUT_FILENO);
    execute(av[ac -2] , env);
}