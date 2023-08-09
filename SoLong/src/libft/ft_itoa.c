/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:03:16 by iggonzal          #+#    #+#             */
/*   Updated: 2023/08/10 01:09:25 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_size(int num)
{
	int	x;

	x = 0;
	while (num != 0)
	{
		x++;
		num /= 10;
	}
	return (x);
}

static char	*allocate(int size)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}

static char	*negative(long nb)
{
	int		size;
	char	*ptr;
	int		i;

	nb *= -1;
	size = ft_size(nb) + 1;
	ptr = allocate(size);
	if (!ptr)
		return (NULL);
	i = size;
	ptr[i--] = '\0';
	while (nb != 0)
	{
		ptr[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	ptr[i] = '-';
	return (ptr);
}

static char	*positive(long nb)
{
	int		size;
	char	*ptr;
	int		i;

	size = ft_size(nb);
	ptr = allocate(size);
	if (!ptr)
		return (NULL);
	i = size;
	ptr[i--] = '\0';
	while (nb != 0)
	{
		ptr[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*ptr;

	nb = n;
	if (nb < 0)
	{
		ptr = negative(nb);
	}
	else if (nb > 0)
	{
		ptr = positive(nb);
	}
	else
	{
		ptr = allocate(1);
		ptr[0] = '0';
		ptr[1] = '\0';
	}
	if (!ptr)
		return (NULL);
	return (ptr);
}
