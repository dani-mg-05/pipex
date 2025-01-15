/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:40:58 by damedina          #+#    #+#             */
/*   Updated: 2025/01/14 10:41:03 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static char	*free_ptr(char *str, char *tmp)
{
	if (str)
		free(str);
	if (tmp)
		free(tmp);
	return (0);
}

static char	*read_buffer_size(int fd, char *str)
{
	char	*tmp;
	char	*new_str;
	int		bytes_read;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (free_ptr(str, 0));
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_ptr(str, tmp));
		tmp[bytes_read] = '\0';
		new_str = ft_strjoin(str, tmp);
		if (!new_str)
			return (free_ptr(str, tmp));
		free(str);
		str = new_str;
	}
	free(tmp);
	return (str);
}

static char	*get_line_from_str(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		ret = (char *)malloc((i + 2) * sizeof(char));
	else
		ret = (char *)malloc((i + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = -1;
	while (str[++i] != '\n' && str[i] != '\0')
		ret[i] = str[i];
	if (str[i] == '\n')
		ret[i] = str[i];
	else
		i--;
	ret[i + 1] = '\0';
	return (ret);
}

static char	*new_str(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (free_ptr(str, 0));
	ret = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!ret)
		return (free_ptr(str, ret));
	j = 0;
	while (str[++i] != '\0')
		ret[j++] = str[i];
	ret[j] = '\0';
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!str)
		str = ft_strdup("");
	str = read_buffer_size(fd, str);
	if (!str)
		return (0);
	ret = get_line_from_str(str);
	if (!ret)
	{
		free(str);
		str = 0;
		return (0);
	}
	str = new_str(str);
	return (ret);
}
