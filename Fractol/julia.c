/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 06:29:36 by drestles          #+#    #+#             */
/*   Updated: 2019/01/11 00:35:40 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_param(t_mandelbrot *mb, t_param *param)
{
	mb->new_re = 1.5 * ((mb->x - param->w / 2) /
	(0.5 * param->zoom * param->w) + param->x_0);
	mb->new_im = (mb->y - param->h / 2) /
	(0.5 * param->zoom * param->h) + param->y_0;
	mb->i = 0;
}

void	julia(t_param *param)
{
	t_mandelbrot mb;

	mb.y = -1;
	while (++mb.y <= param->h)
	{
		mb.x = -1;
		while (++mb.x <= param->w)
		{
			julia_param(&mb, param);
			while (mb.i < param->max_iterations)
			{
				mb.old_re = mb.new_re;
				mb.old_im = mb.new_im;
				mb.new_re = mb.old_re * mb.old_re -
				mb.old_im * mb.old_im + param->cre_s;
				mb.new_im = 2 * mb.old_re * mb.old_im + param->cim_s;
				if ((mb.new_re * mb.new_re + mb.new_im * mb.new_im) > 16)
					break ;
				mb.i++;
			}
			draw_pixels(&mb, param);
		}
	}
	mlx_put_image_to_window(param->mlx_ptr,
	param->win_ptr, param->image, 0, 0);
}

float	abs_f(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	b_s_param(t_mandelbrot *mb, t_param *param)
{
	mb->pr = 3 * ((mb->x - param->w / 2) /
	(0.5 * param->zoom * param->w) + param->x_0);
	mb->pi = 1.5 * (mb->y - param->h / 2) /
	(0.5 * param->zoom * param->h) + param->y_0;
	mb->new_re = 0;
	mb->new_im = 0;
	mb->old_re = 0;
	mb->old_im = 0;
	mb->i = 0;
}

void	b_s(t_param *param)
{
	t_mandelbrot mb;

	mb.y = -1;
	while (++mb.y < param->h)
	{
		mb.x = -1;
		while (++mb.x < param->w)
		{
			b_s_param(&mb, param);
			while (mb.i < param->max_iterations)
			{
				mb.old_re = abs_f(mb.new_re);
				mb.old_im = abs_f(mb.new_im);
				mb.new_re = mb.old_re * mb.old_re
				- mb.old_im * mb.old_im + mb.pr;
				mb.new_im = 2 * mb.old_re * mb.old_im + mb.pi;
				if ((mb.new_re * mb.new_re + mb.new_im * mb.new_im) > 16)
					break ;
				mb.i++;
			}
			draw_pixels(&mb, param);
		}
	}
	mlx_put_image_to_window(param->mlx_ptr,
	param->win_ptr, param->image, 0, 0);
}
