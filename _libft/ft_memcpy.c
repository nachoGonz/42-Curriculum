/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:52:20 by iggonzal          #+#    #+#             */
/*   Updated: 2023/01/05 12:19:02 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	void	*tmp;

	tmp = dst;
	if (!dst && ! src)
		return (NULL);
	while (len--)
		*((unsigned char *) dst++) = *((unsigned char *) src++);
	return (tmp);
}
