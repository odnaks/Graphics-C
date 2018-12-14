/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:21:12 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/21 22:21:13 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rbtcmp(t_rbtree *node1, t_rbtree *node2)
{
	return (ft_memcmp((node1->content), (node2->content),
			node1->content_size > node2->content_size ?
			node1->content_size :
			node2->content_size));
}
