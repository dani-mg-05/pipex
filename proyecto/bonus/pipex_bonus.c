/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:20:59 by damedina          #+#    #+#             */
/*   Updated: 2025/01/11 17:21:07 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	exit_program(int fd_size, int **fd)
{
	int	i;
	int	status;

	i = -1;
	while (++i < fd_size)
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	free_fd(fd, fd_size);
	exit(status);
}

static void	here_doc_aux(int argc, char **argv, char **envp, int **fd)
{
	pid_t	childpid;
	int		i;

	get_pipe(fd, 0, argc - 4);
	childpid = get_childpid(fd, argc - 4);
	if (childpid == 0)
		child1_here_doc(argv, envp, fd[0]);
	i = 3;
	while (++i < argc - 1)
	{
		if (i != argc - 2)
			get_pipe(fd, i - 3, argc - 4);
		childpid = get_childpid(fd, argc - 4);
		if (childpid == 0 && i == argc - 2)
			last_child_process(argc, argv, envp, fd[i - 4]);
		if (childpid == 0 && i > 1 && i < argc - 2)
			child_process(argv, envp, fd, i - 4);
		close(fd[i - 4][0]);
		close(fd[i - 4][1]);
	}
	unlink("here_doc");
	exit_program(argc - 4, fd);
}

static void	here_doc(int argc, char **argv, char **envp, int **fd)
{
	int		infile;
	char	*line;
	int		i;

	infile = open_file("here_doc", argc, fd);
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			close(infile);
			free_fd(fd, argc - 4);
			print_error();
		}
		if (ft_strncmp(argv[2], line, ft_strlen(argv[2])) == 0
			&& line[ft_strlen(argv[2])] == '\n')
			break ;
		i = -1;
		while (++i < (int) ft_strlen(line))
			write(infile, &line[i], 1);
		free(line);
	}
	close(infile);
	here_doc_aux(argc, argv, envp, fd);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		**fd;
	pid_t	childpid;

	fd = check_args(argc, argv);
	if (ft_strncmp(argv[1], "here_doc\0", 9) == 0)
		here_doc(argc, argv, envp, fd);
	get_pipe(fd, 0, argc - 3);
	childpid = get_childpid(fd, argc - 3);
	if (childpid == 0)
		child1_process(argv, envp, fd[0]);
	i = 2;
	while (++i < argc - 1)
	{
		if (i != argc - 2)
			get_pipe(fd, i - 2, argc - 3);
		childpid = get_childpid(fd, argc - 3);
		if (childpid == 0 && i == argc - 2)
			last_child_process(argc, argv, envp, fd[i - 3]);
		if (childpid == 0 && i > 1 && i < argc - 2)
			child_process(argv, envp, fd, i - 3);
		close(fd[i - 3][0]);
		close(fd[i - 3][1]);
	}
	exit_program(argc - 3, fd);
}
