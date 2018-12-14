/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:36:37 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/06 00:36:38 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

void	ft_putwstr_fd(wchar_t *str, int fd)
{
	if (!str)
		return ;
	while (*str++)
		ft_putwchar_fd(*str, fd);
}
