/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:12:08 by iggonzal          #+#    #+#             */
/*   Updated: 2023/01/05 11:04:03 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle || haystack == needle)
		return ((char *)&haystack[0]);
	while (len-- && haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && needle[j] && (len - j + 1))
			{
				j++;
			}
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
