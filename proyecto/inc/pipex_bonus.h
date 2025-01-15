/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:34:26 by damedina          #+#    #+#             */
/*   Updated: 2025/01/11 17:29:33 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

# define BUFFER_SIZE 5

void	print_error(void);
int		**check_args(int argc, char **argv);
void	exec_cmd(char *path, char **cmd, char **envp);
void	free_fd(int **fd, int size);
char	*free_split(char **split);
char	*free_path_split(char *path, char **split);
char	**split_modified(char const *s);
char	*get_next_line(int fd);
void	child1_process(char **argv, char **envp, int *fd);
void	last_child_process(int argc, char **argv, char **envp, int *fd);
void	child_process(char **argv, char **envp, int **fd, int i);
void	child1_here_doc(char **argv, char **envp, int *fd);
char	*get_path(char *cmd, char **envp);
pid_t	get_childpid(int **fd, int fd_size);
void	get_pipe(int **fd, int i, int fd_size);
int		open_file(char *file, int argc, int **fd);

#endif
