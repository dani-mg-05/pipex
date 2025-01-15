/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:32:57 by damedina          #+#    #+#             */
/*   Updated: 2024/07/24 23:46:37 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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

static char	*get_path(char *cmd, char **envp)
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

static void	child1_process(char **argv, char **envp, int *fd)
{
	int		infile;
	char	**cmd1;
	char	*path;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		print_error();
	if (dup2(fd[1], STDOUT_FILENO) < 0 || dup2(infile, STDIN_FILENO) < 0)
		print_error();
	close(fd[1]);
	close(infile);
	if (ft_strlen(argv[2]) == 0 && access(argv[2], F_OK | X_OK) != 0)
		print_error();
	cmd1 = split_modified(argv[2]);
	if (!cmd1)
		print_error();
	path = get_path(cmd1[0], envp);
	if (!path)
	{
		free_split(cmd1);
		print_error();
	}
	exec_cmd(path, cmd1, envp);
	exit(0);
}

static void	child2_process(char **argv, char **envp, int *fd)
{
	int		outfile;
	char	**cmd2;
	char	*path;

	close(fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		print_error();
	if (dup2(fd[0], STDIN_FILENO) < 0 || dup2(outfile, STDOUT_FILENO) < 0)
		print_error();
	close(fd[0]);
	close(outfile);
	if (ft_strlen(argv[3]) == 0 && access(argv[3], F_OK | X_OK) != 0)
		print_error();
	cmd2 = split_modified(argv[3]);
	if (!cmd2)
		print_error();
	path = get_path(cmd2[0], envp);
	if (!path)
	{
		free_split(cmd2);
		print_error();
	}
	exec_cmd(path, cmd2, envp);
	exit(0);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fd[2];
	int		status;
	pid_t	childpid;

	check_args(argc, fd, &childpid);
	if (childpid == 0)
		child1_process(argv, envp, fd);
	childpid = fork();
	if (childpid == -1)
		print_error();
	if (childpid == 0)
		child2_process(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	i = -1;
	while (++i < argc - 3)
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	exit(status);
}
