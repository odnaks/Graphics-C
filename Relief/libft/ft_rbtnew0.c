/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtnew0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:12:25 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/21 22:12:26 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_rbtree	*ft_rbtnew0(void const *content, size_t content_size)
{
	t_rbtree *elem;

	elem = (t_rbtree *)malloc(sizeof(t_rbtree));
	if (elem)
	{
		if (!(elem->content = malloc(content_size)))
		{
			free(elem);
			return (0x0);
		}
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
		elem->parent = 0x0;
		elem->color = RB_RED;
		elem->left = 0x0;
		elem->right = 0x0;
	}
	return (elem);
}
