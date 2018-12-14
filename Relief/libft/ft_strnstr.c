/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:01:15 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 17:25:07 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t n)
{
	size_t i;
	size_t j;

	if (!(*sub))
		return ((char *)str);
	i = 0;
	if ((n < ft_strlen(sub)) && (ft_strlen(str)))
		return (0x0);
	while (str[i] && (i <= n - ft_strlen(sub)))
	{
		if (str[i] == sub[0])
		{
			j = 0;
			while (sub[j] && (str[i + j] == sub[j]) && j < n)
				j++;
			if (!sub[j] || (j == n))
				return ((char *)(str + i));
		}
		i++;
	}
	return (0x0);
}
