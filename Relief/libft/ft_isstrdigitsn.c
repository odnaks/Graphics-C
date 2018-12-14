/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrdigitsn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:38:14 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/06 00:38:15 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isstrdigitsn(char *str, size_t n)
{
	if (str)
	{
		while ((n--) && (*str))
		{
			if (!ft_isdigit(*str))
				return (0);
		}
		return (1);
	}
	return (-1);
}
