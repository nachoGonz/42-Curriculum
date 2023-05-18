/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:00:26 by iggonzal          #+#    #+#             */
/*   Updated: 2023/04/30 16:00:28 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char **buffer)
{
	char	*line;
	char	*temp;
	char	*len;

	len = ft_strchr(*buffer, '\n');
	if (len)
	{
		line = ft_substr(*buffer, 0, len - *buffer + 1);
		temp = ft_strdup(len + 1);
		free(*buffer);
		*buffer = temp;
		if (!**buffer)
		{
			free(*buffer);
			*buffer = NULL;
		}
		return (line);
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

static int	ft_read(int fd, char **buffer)
{
	char	*temp;
	char	*buf;
	int		bytes_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (!*buffer)
			*buffer = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(*buffer, buf);
			free(*buffer);
			*buffer = temp;
		}
		if (ft_strchr(*buffer, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	bytes_read = ft_read(fd, &buffer[fd]);
	if (bytes_read < 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (!bytes_read && !buffer[fd])
		return (NULL);
	line = ft_get_line(&buffer[fd]);
	return (line);
}
