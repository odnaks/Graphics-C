/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:29:21 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 21:52:01 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem)
	{
		if (content)
		{
			elem->content = malloc(content_size);
			ft_memcpy(elem->content, content, content_size);
			elem->content_size = content_size;
		}
		else
		{
			elem->content = 0x0;
			elem->content_size = 0;
		}
		elem->next = 0x0;
	}
	return (elem);
}
