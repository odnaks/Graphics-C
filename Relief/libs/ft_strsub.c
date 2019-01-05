/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:16:09 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 06:13:48 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *result;

	if (!s)
		return (0x0);
	if (start + len > (unsigned int)(ft_strlen((char *)s)))
		return (0x0);
	result = (char *)malloc(len + 1);
	if (result)
	{
		result = ft_strncpy(result, s + start, len);
		result[len] = '\0';
		return (result);
	}
	else
		return (0x0);
}
