/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:32:57 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 07:56:33 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clear_elem(void *memory, size_t size)
{
	size ? ft_memdel(&memory) : ft_memdel(&memory);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *elem;

	if (!f)
		return (0x0);
	result = 0x0;
	while (lst)
	{
		elem = f(lst);
		if (elem)
		{
			ft_lstradd(&result, elem);
			lst = lst->next;
		}
		else
		{
			ft_lstdel(&result, *ft_clear_elem);
			return (0x0);
		}
	}
	return (result);
}
