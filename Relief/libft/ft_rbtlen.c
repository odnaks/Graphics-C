/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:12:43 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/21 22:12:45 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_rbtlen(t_rbtree *root)
{
	size_t left;
	size_t rigth;

	if (!root || !root->content)
		return (0);
	left = ft_rbtlen(root->left);
	rigth = ft_rbtlen(root->right);
	return (1 + ((left > rigth) ? left : rigth));
}
