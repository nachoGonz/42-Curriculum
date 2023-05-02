/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:01:08 by iggonzal          #+#    #+#             */
/*   Updated: 2023/02/13 16:25:31 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	size_t	len;
	size_t	i;

	if (!s)
		return (ft_strdup(""));
	len = ft_strlen(s);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = (*f)(i, s[i]);
		++i;
	}
	tmp[i] = 0;
	return (tmp);
}
