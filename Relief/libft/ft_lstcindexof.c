/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstcindexof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:35:42 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/26 16:42:49 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	ft_lstcindexof(t_list *lst, void *content, size_t content_size,
		int (*equ)(t_list *e1, t_list *e2))
{
	int		index;
	t_list	*elem;

	elem = ft_lstnew(content, content_size);
	index = ft_lstindexof(lst, elem, equ);
	free(elem->content);
	free(elem);
	return (index);
}
