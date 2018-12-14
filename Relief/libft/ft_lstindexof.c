/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstindexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:43:03 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/26 16:44:51 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_lstindexof(t_list *lst, t_list *elem, int (*equ)(t_list *e1, t_list *e2))
{
	int index;

	if (!elem || !equ)
		return (-1);
	index = 0;
	while (lst)
	{
		if (equ(lst, elem) == 1)
			return (index);
		lst = lst->next;
		index++;
	}
	return (-1);
}
