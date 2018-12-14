/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:55:44 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 17:16:35 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		len;
	char	*result;

	len = ft_strlen((char *)src);
	result = dest;
	while (*dest)
		dest++;
	while (len--)
		*dest++ = *src++;
	*dest = '\0';
	return (result);
}
