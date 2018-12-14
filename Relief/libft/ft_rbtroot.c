/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtroot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:12:01 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/22 00:41:26 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rbtree	*ft_rbtroot(t_rbtree *elem)
{
	if (elem)
	{
		while (elem->parent)
			elem = elem->parent;
	}
	return (elem);
}
