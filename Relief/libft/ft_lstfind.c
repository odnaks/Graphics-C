/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:44:58 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/26 16:46:05 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, t_list *elem,
		int (*equ)(t_list *e1, t_list *e2))
{
	if (!elem || !equ)
		return (0x0);
	while (lst)
	{
		if (equ(lst, elem) == 1)
			return (lst);
		lst = lst->next;
	}
	return (0x0);
}
