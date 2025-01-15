/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:15:51 by damedina          #+#    #+#             */
/*   Updated: 2025/01/14 17:15:53 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	child1_process(char **argv, char **envp, int *fd)
{
	int		infile;
	char	**cmd;
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
	cmd = split_modified(argv[2]);
	if (!cmd)
		print_error();
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free_split(cmd);
		print_error();
	}
	exec_cmd(path, cmd, envp);
}

void	last_child_process(int argc, char **argv, char **envp, int *fd)
{
	int		outfile;
	char	**cmd;
	char	*path;

	close(fd[1]);
	outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		print_error();
	if (dup2(fd[0], STDIN_FILENO) < 0 || dup2(outfile, STDOUT_FILENO) < 0)
		print_error();
	close(fd[0]);
	close(outfile);
	if (ft_strlen(argv[argc - 2]) == 0
		&& access(argv[argc - 2], F_OK | X_OK) != 0)
		print_error();
	cmd = split_modified(argv[argc - 2]);
	if (!cmd)
		print_error();
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free_split(cmd);
		print_error();
	}
	exec_cmd(path, cmd, envp);
}

void	child_process(char **argv, char **envp, int **fd, int i)
{
	char	**cmd;
	char	*path;

	close(fd[i][1]);
	if (dup2(fd[i][0], STDIN_FILENO) < 0
		|| dup2(fd[i + 1][1], STDOUT_FILENO) < 0)
		print_error();
	close(fd[i][0]);
	close(fd[i + 1][1]);
	cmd = split_modified(argv[i + 3]);
	if (!cmd)
		print_error();
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free_split(cmd);
		print_error();
	}
	exec_cmd(path, cmd, envp);
}

void	child1_here_doc(char **argv, char **envp, int *fd)
{
	int		infile;
	char	**cmd;
	char	*path;

	close(fd[0]);
	infile = open("here_doc", O_RDONLY);
	if (infile < 0)
		print_error();
	if (dup2(fd[1], STDOUT_FILENO) < 0 || dup2(infile, STDIN_FILENO) < 0)
		print_error();
	close(fd[1]);
	close(infile);
	if (ft_strlen(argv[3]) == 0 && access(argv[3], F_OK | X_OK) != 0)
		print_error();
	cmd = split_modified(argv[3]);
	if (!cmd)
		print_error();
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free_split(cmd);
		print_error();
	}
	exec_cmd(path, cmd, envp);
}
