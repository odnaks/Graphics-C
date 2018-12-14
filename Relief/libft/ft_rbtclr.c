/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtclr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:13:08 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/26 16:04:05 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static void	ft_rbtdel(t_rbtree **root, void (*del)(t_rbtree *elem))
{
	if (*root)
	{
		if ((*root)->left)
			ft_rbtdel(&((*root)->left), del);
		if ((*root)->right)
			ft_rbtdel(&((*root)->right), del);
		del(*root);
		free(*root);
		*root = 0x0;
	}
}

void		ft_rbtclr(t_rbtree **node, void (*del)(t_rbtree *elem))
{
	*node = ft_rbtroot(*node);
	ft_rbtdel(node, del);
}
