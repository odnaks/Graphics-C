/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 05:27:04 by drestles          #+#    #+#             */
/*   Updated: 2019/01/11 00:34:58 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_to_img(t_param *f, int x, int y)
{
	if (x >= 0 && x < f->w && y >= 0 && y < f->h)
		*(unsigned int*)(f->data + (x * (f->bpp)) + (y * f->s_l)) = f->color;
}

void	draw_pixels(t_mandelbrot *mb, t_param *param)
{
	if (mb->i < param->max_iterations)
	{
		param->color = 0x340000 - 10000 * (mb->i % 8) + 100000 * param->color_s;
		pixel_to_img(param, mb->x, mb->y);
	}
	else
	{
		param->color = 0x000000;
		pixel_to_img(param, mb->x, mb->y);
	}
}

void	mandel_param(t_mandelbrot *mb, t_param *param)
{
	mb->pr = 1.5 * ((mb->x - param->w / 2)
	/ (0.5 * param->zoom * param->w) + param->x_0);
	mb->pi = (mb->y - param->h / 2)
	/ (0.5 * param->zoom * param->h) + param->y_0;
	mb->new_re = 0;
	mb->new_im = 0;
	mb->old_re = 0;
	mb->old_im = 0;
	mb->i = 0;
}

void	mandel(t_param *param)
{
	t_mandelbrot mb;

	mb.y = -1;
	while (++mb.y < param->h)
	{
		mb.x = -1;
		while (++mb.x < param->w)
		{
			mandel_param(&mb, param);
			while (mb.i < param->max_iterations)
			{
				mb.old_re = mb.new_re;
				mb.old_im = mb.new_im;
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
