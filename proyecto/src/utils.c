/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:44:50 by damedina          #+#    #+#             */
/*   Updated: 2024/07/24 23:46:27 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	print_error(void)
{
	perror("pipex");
	exit(EXIT_FAILURE);
}

void	check_args(int argc, int *fd, pid_t *childpid)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit (1);
	}
	pipe(fd);
	*childpid = fork();
	if (*childpid == -1)
		print_error();
}

void	exec_cmd(char *path, char **cmd, char **envp)
{
	if (execve(path, cmd, envp) == -1)
	{
		free_path_split(path, cmd);
		print_error();
	}
	free_path_split(path, cmd);
}

char	*free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (0);
}

char	*free_path_split(char *path, char **split)
{
	free(path);
	return (free_split(split));
}
