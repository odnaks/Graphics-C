/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstcfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:32:20 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/26 16:35:35 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstcfind(t_list *lst, void *content, size_t content_size,
		int (*equ)(t_list *e1, t_list *e2))
{
	t_list *result;
	t_list *elem;

	elem = ft_lstnew(content, content_size);
	result = ft_lstfind(lst, elem, equ);
	free(elem->content);
	free(elem);
	return (result);
}
