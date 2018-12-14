/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:13:20 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 06:34:49 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*result;
	int		i;

	if (s && f)
	{
		len = ft_strlen((char *)s);
		result = (char *)malloc(len + 1);
		if (result)
		{
			i = -1;
			while (++i < len)
				result[i] = f(s[i]);
			result[len] = '\0';
		}
		return (result);
	}
	return (0x0);
}
