/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:26:04 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 20:30:35 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	unsigned char buff[2];

	if ((unsigned char)c <= 127)
		write(fd, &c, 1);
	else
	{
		buff[0] = 128 + 64 + ((unsigned char)c / 64);
		buff[1] = ((unsigned char)c % 64) + 128;
		write(fd, buff, 2);
	}
}
