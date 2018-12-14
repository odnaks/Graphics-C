/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:13:26 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/22 18:27:58 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memequ(void *m1, void *m2, size_t size)
{
	size_t	i;
	char	*s1;
	char	*s2;

	if (!m1 || !m2)
		return (-1);
	s1 = (char *)m1;
	s2 = (char *)m2;
	i = -1;
	while (++i < size)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
