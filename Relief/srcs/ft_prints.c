/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 11:01:06 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 12:05:32 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

void		ft_print_menu(t_params *params)
{
	int i;

	i = 0;
	while (i < 2560)
	{
		mlx_pixel_put(params->mlx, params->win, i, Y0, 0x9eff00);
		i++;
	}
	mlx_string_put(params->mlx, params->win, 30, 12, 0xfffe18, HELP1);
	mlx_string_put(params->mlx, params->win, 30, 27, 0xfffe18, HELP2);
	mlx_string_put(params->mlx, params->win, 30, 42, 0xfffe18, HELP3);
	mlx_string_put(params->mlx, params->win, 30, 57, 0xfffe18, HELP4);
}

void		ft_print_usage(void)
{
	ft_putendl(M_USG);
	exit(1);
}
