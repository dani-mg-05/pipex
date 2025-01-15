/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 01:30:43 by damedina          #+#    #+#             */
/*   Updated: 2025/01/13 01:30:53 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	free_fd(int **fd, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(fd[i]);
	free(fd);
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
