/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:59:54 by iggonzal          #+#    #+#             */
/*   Updated: 2023/05/09 13:13:10 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	if (*str == '\0')
		return (0);
	return (ft_strlen(str + 1) + 1);
}

char	*ft_strdup(const char *str)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	tmp = (char *)malloc(sizeof(char)
			* (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!tmp)
		return (NULL);
	while (str1[i])
	{
		tmp[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		tmp[i] = str2[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) str;
	while (*tmp)
	{
		if (*tmp == (unsigned char) c)
			return ((char *)tmp);
		tmp++;
	}
	if (!(unsigned char) c)
		return ((char *)tmp);
	return (NULL);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = str[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
