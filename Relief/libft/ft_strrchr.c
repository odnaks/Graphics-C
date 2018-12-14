/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:59:56 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/19 19:00:14 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char		byte;
	const char	*result;

	result = 0x0;
	byte = (char)(c % 256);
	while (*s)
	{
		if (*s == byte)
			result = s;
		s++;
	}
	if (*s == byte)
		result = s;
	return ((char *)result);
}
