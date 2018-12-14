/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:39:18 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/29 22:30:36 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	len;
	char	*result;

	if (!s1 || !s2)
		return (0x0);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if ((len < ft_strlen((char *)s1))
	|| (len < ft_strlen((char *)s2)))
		return (0x0);
	result = (char *)malloc(len + 1);
	if (result)
	{
		i = 0;
		while (*s1++)
			result[i++] = *(s1 - 1);
		while (*s2++)
			result[i++] = *(s2 - 1);
		result[i] = '\0';
	}
	return (result);
}
