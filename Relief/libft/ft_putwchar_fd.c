/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:36:30 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/06 01:18:02 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

void	ft_putwchar_fd(wchar_t c, int fd)
{
	char temp;

	if (c < 0x80)
		ft_putchar_fd((char)c, fd);
	if (c < 0x0400)
	{
		temp = 192 + (c >> 6);
		ft_putchar_fd(temp, fd);
		temp = 128 + (c & 63);
		ft_putchar_fd(temp, fd);
	}
	else
	{
		temp = 224 + (c >> 12);
		ft_putchar_fd(temp, fd);
		temp = 128 + ((c >> 6) & 63);
		ft_putchar_fd(temp, fd);
		temp = 128 + (c & 63);
		ft_putchar_fd(temp, fd);
	}
}
