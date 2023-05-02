/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:05:27 by iggonzal          #+#    #+#             */
/*   Updated: 2023/01/04 15:44:30 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;

	tmp = (unsigned char *) s1;
	tmp2 = (unsigned char *) s2;
	while (len && *tmp == *tmp2)
	{
		++tmp;
		++tmp2;
		--len;
	}
	if (len)
		return (*tmp - *tmp2);
	else
		return (0);
}
