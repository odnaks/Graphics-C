/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:17:22 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 06:14:53 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int len;
	int i;

	if (!s)
		return (0x0);
	len = ft_strlen((char *)s);
	i = 0;
	while ((len > 0) && ((s[len - 1] == ' ') ||
		(s[len - 1] == '\n') || (s[len - 1] == '\t')))
		len--;
	if (len != 0)
	{
		while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
			i++;
		len -= i;
	}
	return (ft_strsub(s, i, len));
}
