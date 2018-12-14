/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:50:12 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/24 13:03:34 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*src_c;
	char	*dest_c;
	size_t	i;

	if (dest == src)
		return (dest);
	dest_c = (char *)dest;
	src_c = (char *)src;
	i = -1;
	if (dest_c < src_c)
		while (++i < n)
			dest_c[i] = src_c[i];
	else
		while (n--)
			dest_c[n] = src_c[n];
	return (dest);
}
