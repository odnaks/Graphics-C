/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 10:29:46 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 10:29:47 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstforeach(t_list *lst, void *params,
		void f(t_list *lst, void *params))
{
	if (!f || !lst)
		return ;
	while (lst)
	{
		f(lst, params);
		lst = lst->next;
	}
}
