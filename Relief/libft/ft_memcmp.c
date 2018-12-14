/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:51:12 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/19 18:52:17 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;
	size_t			i;

	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	i = 0;
	while ((i < n) && (*s1_uc == *s2_uc))
	{
		s1_uc++;
		s2_uc++;
		i++;
	}
	if (i == n)
		return (0);
	else
		return (*s1_uc - *s2_uc);
}
