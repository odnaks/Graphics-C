/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:48:50 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/24 12:59:33 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *dest_c;
	char *src_c;

	if (dest == src)
		return (dest);
	dest_c = (char *)dest;
	src_c = (char *)src;
	while (n--)
		*dest_c++ = *src_c++;
	return (dest);
}
