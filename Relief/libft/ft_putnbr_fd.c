/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:28:05 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 21:48:01 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		ln;
	int		t;
	char	a[12];

	t = n;
	ln = 1 + (n < 0);
	while (t / 10)
	{
		ln++;
		t /= 10;
	}
	t = n;
	a[ln] = '\0';
	while (ln--)
	{
		a[ln] = (t % 10 < 0 ? ('0' - (t % 10)) : ('0' + t % 10));
		t /= 10;
	}
	if (n < 0)
		a[0] = '-';
	ft_putstr_fd(a, fd);
}
