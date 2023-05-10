/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:17:53 by iggonzal          #+#    #+#             */
/*   Updated: 2023/05/07 19:38:25 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_hexadecimal(unsigned int x, int *len, char type)
{
	char	string[25];
	char	*base_char;
	int		i;

	if (type == 'X')
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_char[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(string[i], len);
}
