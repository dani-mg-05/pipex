/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:44:50 by damedina          #+#    #+#             */
/*   Updated: 2025/01/11 17:22:42 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	print_error(void)
{
	perror("pipex");
	exit(EXIT_FAILURE);
}

void	print_usage(void)
{
	ft_putendl_fd("Usage:\t./pipex file1 cmd1 cmd2 ... cmdN file2", 2);
	ft_putendl_fd("\t./pipex here_doc LIMITER cmd1 cmd2 ... cmdN file", 2);
	exit(EXIT_FAILURE);
}

int	**check_args(int argc, char **argv)
{
	int	**fd;
	int	size;
	int	i;

	if (argc < 5 || (ft_strncmp(argv[1], "here_doc\0", 9) == 0 && argc < 6))
		print_usage();
	if (ft_strncmp(argv[1], "here_doc\0", 9) == 0)
		size = argc - 5;
	else
		size = argc - 4;
	fd = malloc((size + 1) * sizeof(int *));
	if (!fd)
		print_error();
	i = -1;
	while (++i < size + 1)
	{
		fd[i] = malloc(2 * sizeof(int));
		if (!fd[i])
		{
			free_fd(fd, i);
			print_error();
		}
	}
	return (fd);
}

void	exec_cmd(char *path, char **cmd, char **envp)
{
	if (execve(path, cmd, envp) == -1)
	{
		free_path_split(path, cmd);
		print_error();
	}
	free_path_split(path, cmd);
	exit(0);
}
