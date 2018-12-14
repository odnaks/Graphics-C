/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:50:44 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/29 15:56:20 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_uc;
	unsigned char	byte;

	s_uc = (unsigned char *)s;
	byte = (unsigned char)(c);
	while (n--)
	{
		if (*s_uc == byte)
			return ((void *)s_uc);
		s_uc++;
	}
	return (0x0);
}
