/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 06:29:36 by drestles          #+#    #+#             */
/*   Updated: 2019/01/10 06:43:06 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_param(t_mandelbrot *mb, t_param *param)
{
	mb->newRe = 1.5 * (mb->x - param->w / 2) / (0.5 * param->zoom * param->w) + param->move_x;
	mb->newIm = (mb->y - param->h / 2) / (0.5 * param->zoom * param->h) + param->move_y;
	mb->i = 0;
}

void	julia(t_param *param)
{
	t_mandelbrot mb;

	mb.y = 0;
	while (mb.y < param->h)
	{
		mb.x = 0;
		while (mb.x < param->w)
		{
			julia_param(&mb, param);
			while (mb.i < param->maxIterations)
			{
				mb.oldRe = mb.newRe;
				mb.oldIm = mb.newIm;
				mb.newRe = mb.oldRe * mb.oldRe - mb.oldIm * mb.oldIm + param->cRe_s;
				mb.newIm = 2 * mb.oldRe * mb.oldIm + param->cIm_s;
				if ((mb.newRe * mb.newRe + mb.newIm * mb.newIm) > 16) break;
					mb.i++;
			}
			draw_pixels(&mb, param);
			mb.x++;
		}
		mb.y++;
	}
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_put_image_to_window (param->mlx_ptr, param->win_ptr, param->image, 0, 0);	
}


float	abs_f(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	b_s(t_param *param)
{
	t_mandelbrot mb;

	mb.y = 0;
	while (mb.y < param->h)
	{
		mb.x = 0;
		while (mb.x < param->w)
		{
			mandel_param(&mb, param);
			while (mb.i < param->maxIterations)
			{
				mb.oldRe = abs_f(mb.newRe);
				mb.oldIm = abs_f(mb.newIm);
				mb.newRe = mb.oldRe * mb.oldRe - mb.oldIm * mb.oldIm + mb.pr;
				mb.newIm = 2 * mb.oldRe * mb.oldIm + mb.pi;
				if ((mb.newRe * mb.newRe + mb.newIm * mb.newIm) > 16) break;
					mb.i++;
			}
			draw_pixels(&mb, param);
			mb.x++;
		}
		mb.y++;
	}
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_put_image_to_window (param->mlx_ptr, param->win_ptr, param->image, 0, 0);
}