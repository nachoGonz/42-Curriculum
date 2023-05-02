/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:46:34 by iggonzal          #+#    #+#             */
/*   Updated: 2023/02/13 16:08:13 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	len;
	size_t	len2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (len + len2 + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1, len + 1);
	ft_strlcat(tmp, s2, len + len2 + 1);
	return (tmp);
}
