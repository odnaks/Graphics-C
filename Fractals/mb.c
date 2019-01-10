/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 05:27:04 by drestles          #+#    #+#             */
/*   Updated: 2019/01/10 06:45:01 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pixel_to_img(t_param *f, int x, int y)
{
	if (x >= 0 && x < f->w && y >= 0 && y < f->h)
		*(unsigned int*)(f->data + (x * (f->bpp)) + (y * f->s_l)) = f->color;
}


void	draw_pixels(t_mandelbrot *mb, t_param *param)
{
	if (mb->i < param->maxIterations)
		{
 			param->color = 0x340000 - 10000 * (mb->i % 8);
			pixel_to_img (param, mb->x, mb->y);
		}
	else
		{
			param->color = 0x000000;
			pixel_to_img (param, mb->x, mb->y);
		}
}

void	mandel_param(t_mandelbrot *mb, t_param *param)
{
	mb->pr = 1.5 * (mb->x - param->w / 2) / (0.5 * param->zoom * param->w) + param->move_x;
	mb->pi = (mb->y - param->h / 2) / (0.5 * param->zoom * param->h) + param->move_y;
	mb->newRe = mb->newIm = mb->oldRe = mb->oldIm = mb->i = 0;
}

void	mandel(t_param *param)
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
				mb.oldRe = mb.newRe;
				mb.oldIm = mb.newIm;
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

int		draw_fract(t_param *param)
{
	if (param->fractal == 2)
	{
		mandel(param);
		return (0);
	}
	if (param->fractal == 1)
	{
		julia(param);
		return (0);
	}
	if (param->fractal == 3)
	{
		b_s(param);
		return (0);
	}
	return (0);
}
