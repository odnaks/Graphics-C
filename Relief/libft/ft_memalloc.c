/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:44:32 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/19 19:09:52 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*memory;

	memory = malloc(size);
	if (memory)
		return (ft_memset(memory, 0, size));
	else
		return (0x0);
}
