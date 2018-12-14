/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:30:55 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 07:54:05 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *next;

	if (!alst || !del)
		return ;
	temp = *alst;
	while (temp)
	{
		next = temp->next;
		ft_lstdelone(&temp, del);
		temp = next;
	}
	*alst = 0x0;
}
