/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 05:27:21 by drestles          #+#    #+#             */
/*   Updated: 2019/01/11 00:34:46 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_arg(int n, char **arg, t_param *param)
{
	if (n == 2)
	{
		if (ft_strcmp(arg[1], "julia") == 0)
		{
			param->fractal = 1;
			return (1);
		}
		if (ft_strcmp(arg[1], "mandelbrot") == 0)
		{
			param->fractal = 2;
			return (1);
		}
		if (ft_strcmp(arg[1], "burning-ship") == 0)
		{
			param->fractal = 3;
			return (1);
		}
		else
		{
			write(1, "error\n\njulia\nmandelbrot\nburning-ship", 36);
			return (0);
		}
	}
	write(1, "error\n\n./fractol [fractal name]", 31);
	return (0);
}

int		key_button(int button, t_param *param)
{
	if (button == 53)
		exit(1);
	if (button == 69)
		param->zoom *= 1.2;
	if (button == 78)
		param->zoom /= 1.2;
	if (button == 124)
		param->x_0 += (1 / param->zoom);
	if (button == 123)
		param->x_0 -= (1 / param->zoom);
	if (button == 126)
		param->y_0 -= (1 / param->zoom);
	if (button == 125)
		param->y_0 += (1 / param->zoom);
	if (button == 258)
		param->color_s = ((param->color_s) + 1) % 3;
	draw_fract(param);
	return (0);
}

int		mouse_zoom(int button, int x, int y, t_param *param)
{
	if (x < 0 || x > param->w || y < 0 || y > param->h)
		return (0);
	if (button == 5)
	{
		param->zoom *= 1.2;
		draw_fract(param);
	}
	if (button == 4)
	{
		param->zoom /= 1.2;
		draw_fract(param);
	}
	return (0);
}

int		mouse_move(int x, int y, t_param *param)
{
	if (x < param->w && x > 0 && y < param->h && y > 0)
	{
		param->cre_s = 1.5 * (x - param->w / 2) / (0.5 * param->w);
		param->cim_s = (y - param->h / 2) / (0.5 * param->h);
		draw_fract(param);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_param	param;

	if (check_arg(argc, argv, &param) == 0)
		return (0);
	init_mlx(&param);
	draw_fract(&param);
	mlx_hook(param.win_ptr, 2, 0, key_button, &param);
	mlx_hook(param.win_ptr, 4, 0, mouse_zoom, &param);
	mlx_hook(param.win_ptr, 6, 0, mouse_move, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
