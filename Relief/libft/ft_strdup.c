/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:53:23 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 17:32:38 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*result;

	len = ft_strlen(str);
	result = (char *)malloc(len + 1);
	if (result)
	{
		i = 0;
		while (i <= len)
		{
			result[i] = str[i];
			i++;
		}
	}
	return (result);
}
