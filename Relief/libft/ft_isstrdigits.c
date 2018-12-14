/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:38:04 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/06 00:38:04 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isstrdigits(char *str)
{
	if (!str)
		return (-1);
	return (ft_isstrdigitsn(str, ft_strlen(str)));
}
