/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:18:05 by prossi            #+#    #+#             */
/*   Updated: 2023/05/07 13:40:48 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_putchar_len(char character, int *len)
{
	write(1, &character, 1);
	(*len)++;
}

void	ft_string(char *args, int *len)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putchar_len(args[i], len);
		i++;
	}
}
