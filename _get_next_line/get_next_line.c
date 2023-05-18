/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:58:54 by iggonzal          #+#    #+#             */
/*   Updated: 2023/05/09 13:28:14 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char **buffer)
{
	char	*line;
	char	*tmp;
	char	*len;

	len = ft_strchr(*buffer, '\n');
	if (len)
	{
		line = ft_substr(*buffer, 0, len - *buffer + 1);
		tmp = ft_strdup(len + 1);
		free(*buffer);
		*buffer = tmp;
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
	char	*tmp;
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
			tmp = ft_strjoin(*buffer, buf);
			free(*buffer);
			*buffer = tmp;
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
	static char	*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = ft_read(fd, &buffer);
	if (!bytes_read && !buffer)
		return (NULL);
	if (bytes_read < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (ft_get_line(&buffer));
}
