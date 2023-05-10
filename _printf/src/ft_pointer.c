/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:16:54 by iggonzal          #+#    #+#             */
/*   Updated: 2023/05/08 12:31:09 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_pointer(size_t pointer, int *len)
{
	char	string[25];
	int		i;
	char	*base_char;

	base_char = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (pointer == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (pointer != 0)
	{
		string[i] = base_char[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(string[i], len);
}
