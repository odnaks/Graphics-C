/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnequ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:15:29 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 06:35:04 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		while ((i < n) && s1[i] && s2[i] && (s1[i] == s2[i]))
			i++;
		if (i == n)
			return (1);
		return (((unsigned char)(s1[i]) - (unsigned char)(s2[i])) == 0);
	}
	return (-1);
}
