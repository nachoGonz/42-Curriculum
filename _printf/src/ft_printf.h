/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:23:41 by iggonzal          #+#    #+#             */
/*   Updated: 2023/05/04 14:31:14 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Standard C Libraries

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

// Protoypes

void			ft_putchar_len(char character, int *len);
void			ft_string(char *args, int *len);

void			ft_number(int number, int *len);
void			ft_hexadecimal(unsigned int x, int *len, char type);
void			ft_unsigned_int(unsigned int u, int *len);
void			ft_pointer(size_t pointer, int *len);

int				ft_printf(const char *string, ...);

#endif