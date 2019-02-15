/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswapc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 10:29:59 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 10:30:00 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswapc(t_list *elem1, t_list *elem2)
{
	void	*content;
	size_t	content_size;

	if (!elem1 || !elem2)
		return ;
	content = elem1->content;
	content_size = elem1->content_size;
	elem1->content = elem2->content;
	elem1->content_size = elem2->content_size;
	elem2->content = content;
	elem2->content_size = content_size;
}
