/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindcontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 10:29:25 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 10:29:26 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_lstfindcontent(t_list *lst, void *content, int equ(void *, void *))
{
	while (lst)
	{
		if (equ(lst->content, content))
			return (lst->content);
		lst = lst->next;
	}
	return (0x0);
}
