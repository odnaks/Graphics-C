/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:13:59 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 06:11:22 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*result;
	unsigned int	i;

	if (s && f)
	{
		len = (unsigned int)ft_strlen((char *)s);
		result = (char *)malloc(len + 1);
		if (result)
		{
			i = -1;
			while (++i < len)
				result[i] = f(i, s[i]);
			result[len] = '\0';
		}
		return (result);
	}
	return (0x0);
}
