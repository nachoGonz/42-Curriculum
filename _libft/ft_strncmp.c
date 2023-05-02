/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:51:00 by iggonzal          #+#    #+#             */
/*   Updated: 2023/01/04 14:59:59 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (!len)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < len - 1)
		++i;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
