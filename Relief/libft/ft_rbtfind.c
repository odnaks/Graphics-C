/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtfind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:13:01 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/21 22:13:02 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rbtree	*ft_rbtfind(t_rbtree *root, t_rbtree *elem,
		int (*cmp)(t_rbtree *elem1, t_rbtree *elem2))
{
	int temp;

	if (root)
		while (root->content)
		{
			temp = cmp(root, elem);
			if (!temp)
				return (root);
			root = (temp < 0 ? root->right : root->left);
		}
	return (0x0);
}
