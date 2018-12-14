/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:49:17 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/30 15:23:26 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *dest_c;
	char *src_c;

	dest_c = (char *)dest;
	src_c = (char *)src;
	while (n--)
	{
		if (*src_c == (char)(c % 256))
		{
			*dest_c++ = *src_c;
			return ((void *)dest_c);
		}
		*dest_c++ = *src_c++;
	}
	if (dest_c == src_c)
		return ((void *)dest_c);
	return (0x0);
}
