/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:41:09 by iggonzal          #+#    #+#             */
/*   Updated: 2023/01/05 10:54:21 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	size_t	first;
	size_t	last;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	last = ft_strlen(s1) - 1;
	first = 0;
	while (s1[first] && ft_strchr(set, s1[first]))
		++first;
	while (s1[last] && ft_strchr(set, s1[last]))
		--last;
	tmp = ft_substr(s1, first, last - first + 1);
	return (tmp);
}
