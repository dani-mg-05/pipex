/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vars_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:12:54 by damedina          #+#    #+#             */
/*   Updated: 2025/01/14 17:12:57 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static char	*get_path_aux(char	**paths_envp, char *cmd, int i)
{
	char	*path;
	char	*path_aux;

	while (paths_envp[++i])
	{
		path_aux = ft_strjoin(paths_envp[i], "/");
		if (!path_aux)
			return (free_split(paths_envp));
		path = ft_strjoin(path_aux, cmd);
		free(path_aux);
		if (!path)
			return (free_split(paths_envp));
		if (access(path, F_OK | X_OK) == 0)
		{
			free_split(paths_envp);
			return (path);
		}
		free(path);
	}
	free_split(paths_envp);
	return (0);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths_envp;
	int		i;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (envp[i + 5] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i + 5])
		return (0);
	paths_envp = ft_split(ft_strchr(envp[i], '/'), ':');
	if (!paths_envp)
		return (0);
	return (get_path_aux(paths_envp, cmd, -1));
}

pid_t	get_childpid(int **fd, int fd_size)
{
	int	childpid;

	childpid = fork();
	if (childpid == -1)
	{
		free_fd(fd, fd_size);
		print_error();
	}
	return (childpid);
}

void	get_pipe(int **fd, int i, int fd_size)
{
	pipe(fd[i]);
	if (fd[i][0] < 0 || fd[i][1] < 0)
	{
		free_fd(fd, fd_size);
		print_error();
	}
}

int	open_file(char *file, int argc, int **fd)
{
	int	infile;

	infile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile < 0)
	{
		free_fd(fd, argc - 4);
		print_error();
	}
	return (infile);
}
