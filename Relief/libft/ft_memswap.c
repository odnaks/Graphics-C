/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memswap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:52:41 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/21 23:52:44 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_memswap(void *mem1, void *mem2, size_t size)
{
	char arr[MEMSWAP_SIZE];
	char *all;

	if (size <= MEMSWAP_SIZE)
	{
		ft_bzero(arr, MEMSWAP_SIZE);
		ft_memmove(arr, mem1, size);
		ft_memmove(mem1, mem2, size);
		ft_memmove(mem2, arr, size);
		return ;
	}
	if ((all = malloc(size)))
	{
		ft_memmove(all, mem1, size);
		ft_memmove(mem1, mem2, size);
		ft_memmove(mem2, all, size);
		free(all);
	}
}
