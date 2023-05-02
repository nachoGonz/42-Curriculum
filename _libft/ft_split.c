/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:29:29 by iggonzal          #+#    #+#             */
/*   Updated: 2023/01/05 11:32:40 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++count;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

static void	ft_split_str(char **arr, char const *s, char c)
{
	char		**tmp_arr;
	char const	*tmp;

	tmp = s;
	tmp_arr = arr;
	while (*tmp)
	{
		while (*s == c)
			++s;
		tmp = s;
		while (*tmp && *tmp != c)
			++tmp;
		if (*tmp == c || tmp > s)
		{
			*tmp_arr = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tmp_arr;
		}
	}
	*tmp_arr = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_count_words(s, c);
	tmp = (char **) malloc(sizeof(char *) * (len + 1));
	if (!tmp)
		return (NULL);
	ft_split_str(tmp, s, c);
	return (tmp);
}
