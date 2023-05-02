/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:00:34 by iggonzal          #+#    #+#             */
/*   Updated: 2023/01/04 15:01:26 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) s;
	while (len--)
	{
		if (*tmp == (unsigned char)c)
			return ((void *) tmp);
		tmp++;
	}
	return (NULL);
}
