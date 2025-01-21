/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:17:13 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/21 23:33:20 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc(char **argv, char **env, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], env);
	error();
}

void	parent_proc(char **argv, char **env, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], env);
	error();
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid1 , pid2;
	
	// if (argc == 5)
	// {
	// 	if (pipe(fd) == -1)
	// 		error();
	// 	pid = fork();
	// 	if (pid == -1)
	// 		error();
	// 	if (pid == 0)
	// 		child_proc(argv, env, fd);
	// 	waitpid(pid, NULL, 0);
	// 	parent_proc(argv, env, fd);
	// }
	    if (argc == 5)
    {
        if (pipe(fd) == -1)
            error();
            
        pid1 = fork();
        if (pid1 == -1)
            error();
            
        if (pid1 == 0)
		{
            child_proc(argv, env, fd);
			exit(1);
		}
        pid2 = fork();  // Create second process
        if (pid2 == -1)
            error();
            
        if (pid2 == 0)
        {  
		    parent_proc(argv, env, fd);
			exit(1);
		}
        // Close pipe in main process
        close(fd[0]);
        close(fd[1]);
        
 		int status1, status2;
        waitpid(pid1, &status1, 0);
        waitpid(pid2, &status2, 0);
        
        if (WIFEXITED(status1))
            return WEXITSTATUS(status1);
        return 1;
    }
	else
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
}
