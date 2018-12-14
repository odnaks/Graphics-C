/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:12:35 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/21 22:12:36 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_rbtree	*ft_rbtnewleaf(void)
{
	t_rbtree	*leaf;

	leaf = (t_rbtree *)malloc(sizeof(t_rbtree));
	if (leaf)
	{
		leaf->content = 0x0;
		leaf->content_size = 0;
		leaf->left = 0x0;
		leaf->right = 0x0;
		leaf->color = RB_BLACK;
		leaf->parent = 0x0;
	}
	return (leaf);
}

static t_rbtree	*ft_rbtnewmalloc(size_t content_size)
{
	t_rbtree *elem;

	if ((elem = (t_rbtree *)malloc(sizeof(t_rbtree))))
	{
		if (!(elem->left = ft_rbtnewleaf()))
			free(elem);
		else if (!(elem->right = ft_rbtnewleaf()))
		{
			free(elem->left);
			free(elem);
		}
		else if (!(elem->content = malloc(content_size)))
		{
			free(elem->left);
			free(elem->right);
			free(elem);
		}
		else
		{
			elem->left->parent = elem;
			elem->right->parent = elem;
			return (elem);
		}
	}
	return (0x0);
}

t_rbtree		*ft_rbtnew(void const *content, size_t content_size)
{
	t_rbtree *elem;

	elem = ft_rbtnewmalloc(content_size);
	if (elem)
	{
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
		elem->parent = 0x0;
		elem->color = RB_RED;
	}
	return (elem);
}
