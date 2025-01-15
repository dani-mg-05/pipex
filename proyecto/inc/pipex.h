/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:34:26 by damedina          #+#    #+#             */
/*   Updated: 2024/07/24 22:35:00 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

void	print_error(void);
void	check_args(int argc, int *fd, int *childpid);
void	exec_cmd(char *path, char **cmd, char **envp);
char	*free_split(char **split);
char	*free_path_split(char *path, char **split);
char	**split_modified(char const *s);

#endif
