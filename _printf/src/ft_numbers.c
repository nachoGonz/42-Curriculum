/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:23:29 by iggonzal          #+#    #+#             */
/*   Updated: 2023/05/07 13:17:45 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_number(int number, int *len)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (number < 0)
	{
		ft_putchar_len('-', len);
		ft_number(number * -1, len);
	}
	else
	{
		if (number > 9)
			ft_number(number / 10, len);
		ft_putchar_len(number % 10 + '0', len);
	}
}

void	ft_unsigned_int(unsigned int u, int *len)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, len);
	ft_putchar_len(u % 10 + '0', len);
}
