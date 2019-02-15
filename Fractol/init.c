/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:24:09 by drestles          #+#    #+#             */
/*   Updated: 2019/01/11 00:34:52 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_param *param)
{
	param->zoom = 1;
	param->h = 500;
	param->w = 500;
	param->plus = 1;
	param->mlx_ptr = mlx_init();
	param->win_ptr =
	mlx_new_window(param->mlx_ptr, param->w, param->h, "fract'ol");
	param->w = 500;
	param->h = 500;
	param->image = mlx_new_image(param->mlx_ptr, param->w, param->h);
	param->data = mlx_get_data_addr(param->image,
	&param->bpp, &param->s_l, &param->end);
	param->bpp /= 8;
	if (param->fractal == 2)
		param->x_0 = -0.5;
	if (param->fractal == 3)
		param->y_0 = -0.4;
	param->max_iterations = 50;
	param->cre_s = -0.7269;
	param->cim_s = 0.1889;
}
