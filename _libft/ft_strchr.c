/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:37:50 by iggonzal          #+#    #+#             */
/*   Updated: 2023/01/04 15:00:11 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) s;
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
