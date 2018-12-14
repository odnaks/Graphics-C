/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:58:51 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/23 10:20:35 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t result;

	result = ft_strlen((char *)src);
	result += ((size_t)ft_strlen(dest) < size ? (size_t)ft_strlen(dest) : size);
	while (*dest && size)
	{
		dest++;
		size--;
	}
	if (!size)
		return (result);
	while (--size && *src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (result);
}
