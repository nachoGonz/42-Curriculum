/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:20:51 by iggonzal          #+#    #+#             */
/*   Updated: 2023/01/04 15:41:33 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	long int	tmp;
	int			sign;

	sign = 1;
	tmp = 0;
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		++nptr;
	while (ft_isdigit(*nptr))
	{
		tmp = tmp * 10 + (*nptr - 48);
		++nptr;
	}
	return (tmp * sign);
}
