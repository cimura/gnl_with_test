/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:44:02 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/15 23:54:57 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*leftovers[FD_MAX];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || FD_MAX <= fd)
		return (NULL);
	if (leftovers[fd] == NULL)
	{
		leftovers[fd] = malloc(1);
		if (!leftovers[fd])
			return (NULL);
		leftovers[fd][0] = '\0';
	}
	line = check_newline(&leftovers[fd]);
	if (line != NULL)
		return (line);
	line = read_and_join(fd, &leftovers[fd]);
	if (line != NULL)
		return (line);
	return (finalize_line(&leftovers[fd]));
}

char	*check_newline(char **leftover)
{
	char	*newline_pos;
	char	*found_newline;
	char	*tmp;

	newline_pos = ft_strchr(*leftover, '\n');
	if (newline_pos != NULL)
	{
		*newline_pos = '\0';
		found_newline = ft_strjoin(*leftover, "\n");
		tmp = ft_strdup(newline_pos + 1);
		free(*leftover);
		*leftover = tmp;
		return (found_newline);
	}
	return (NULL);
}

char	*read_and_join(int fd, char **leftover)
{
	ssize_t	bytes_read;
	char	*buf;
	char	*line;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = NULL;
	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buf[bytes_read] = '\0';
		line = handle_read(buf, leftover);
		if (line != NULL)
			break ;
	}
	free(buf);
	if (bytes_read == -1)
	{
		free(*leftover);
		*leftover = NULL;
	}
	return (line);
}

char	*handle_read(char *buf, char **leftover)
{
	char	*for_change;

	for_change = ft_strjoin(*leftover, buf);
	free(*leftover);
	*leftover = for_change;
	return (check_newline(leftover));
}

char	*finalize_line(char **leftover)
{
	char	*line;

	line = NULL;
	if (*leftover && **leftover)
	{
		line = ft_strdup(*leftover);
		free(*leftover);
		*leftover = NULL;
		return (line);
	}
	free(*leftover);
	*leftover = NULL;
	return (line);
}
