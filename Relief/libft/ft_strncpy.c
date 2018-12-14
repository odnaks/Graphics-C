/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:54:53 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 05:43:39 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*result;

	result = dest;
	while (n--)
	{
		if (*src)
			*dest = *src++;
		else
			*dest = '\0';
		dest++;
	}
	return (result);
}
