/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:43:47 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/29 15:58:13 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	byte;
	size_t			i;
	char			*temp;

	temp = (char *)s;
	byte = (char)(c);
	i = 0;
	while (i < n)
		temp[i++] = byte;
	return (s);
}
