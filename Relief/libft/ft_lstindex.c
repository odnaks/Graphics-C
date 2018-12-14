/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstindex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:46:36 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/26 16:47:07 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstindex(t_list *lst, int index)
{
	int i;

	if (index < 0)
		return (0x0);
	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst);
		lst = lst->next;
		i++;
	}
	return (0x0);
}
