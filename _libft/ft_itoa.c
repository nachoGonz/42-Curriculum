/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:45:25 by iggonzal          #+#    #+#             */
/*   Updated: 2023/02/13 16:07:12 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(int n)
{
	if (n >= 10)
		return (ft_getlen(n / 10) + 1);
	else if (n <= -10)
		return (ft_getlen(n / -10) + 2);
	else if (n < 0)
		return (2);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	int		len;

	len = ft_getlen(n);
	tmp = (char *)ft_calloc(len + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	if (n == 0)
		tmp[0] = '0';
	if (n < 0)
	{
		tmp[0] = '-';
		if (n == -2147483648)
		{
			tmp[--len] = '8';
			n /= 10;
		}
		n = -n;
	}
	while (len-- && n != 0)
	{
		tmp[len] = '0' + (n % 10);
		n /= 10;
	}
	return (tmp);
}
