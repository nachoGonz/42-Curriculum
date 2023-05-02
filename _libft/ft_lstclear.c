/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:12:30 by iggonzal          #+#    #+#             */
/*   Updated: 2023/02/13 16:04:56 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstrec(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (lst->next != NULL)
		ft_lstrec(lst->next, (*del));
	ft_lstdelone(lst, (*del));
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	ft_lstrec(*lst, (*del));
	*lst = NULL;
}
