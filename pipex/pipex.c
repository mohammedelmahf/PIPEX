/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:17:13 by maelmahf          #+#    #+#             */
/*   Updated: 2024/12/31 16:00:19 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    #include"pipex.h"

    void    child_proc(char **argv ,char **env ,int *fd)
    {
        int filein;

        filein = open(argv[1] ,O_RDONLY, 0777);

        if(filein == -1)
            error();
        dup2(fd[1] , STDIN_FILENO);
        dup2(filein, STDOUT_FILENO);
        close(fd[0]);
        execute(argv[2] , env);
    }
    void    parent_proc(char **argv ,char **env ,int *fd)
    {
        int fileout;

        fileout = open(argv[4] , O_RDONLY ,O_CREAT ,O_TRUNC ,0777);

        if(fileout == -1)
            error();
        dup2(fd[0] , STDIN_FILENO);
        dup2(fileout , STDOUT_FILENO);
        clode(fd[1]);
        execute(argv[3] ,env);
    }

    int main(int argc, char **argv , char **env)
    {
        int fd[2];
        pid_t  pid; 
        
        if(argc = 5)
        {
            if(pipe(fd) == -1)
                error();
            pid = fork();
            if(pid == -1)
                error();
            if(pid == 0)
                child_proc(argv , env,fd);
            parent_proc(argv ,env ,fd);
        }
        else
        {
            ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
            ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
        }
    }