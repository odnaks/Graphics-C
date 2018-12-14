/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:11:50 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/21 22:11:52 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_rbtsize(t_rbtree *root)
{
	if (!root || !root->content)
		return (0);
	return (ft_rbtsize(root->left) + ft_rbtsize(root->right) + 1);
}
