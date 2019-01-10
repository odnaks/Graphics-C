/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 05:27:21 by drestles          #+#    #+#             */
/*   Updated: 2019/01/10 06:43:01 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//printf
#include <stdio.h>

void	init_mlx(t_param *param)
{
	param->zoom = 1;
	param->h = 500;
	param->w = 500;
	param->move_x = 0;
	param->move_y = 0;
	param->plus = 1;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->w, param->h, "fract'ol");
	param->image = mlx_new_image(param->mlx_ptr, param->w = 500, param->h = 500);
	param->data = mlx_get_data_addr (param->image, &param->bpp, &param->s_l, &param->end);
	param->bpp /= 8;
	if (param->fractal != 1)
		param->move_x = -0.5;
	param->maxIterations = 30;
	param->cRe_s = -0.7269;
	param->cIm_s = 0.1889;
}

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
				write (1, "error\n\njulia\nmandelbrot\nburning-ship", 36);
				return (0);
			}
	}
	write (1, "error\n\n./fractol [fractal name]", 31);
	return (0);
}

int	key_button(int button, t_param *param)
{
	if (button == 53)
		exit(1);
	if (button == 69)
	{
		if (param->zoom > 197)
			return (0);
		param->plus *= 2.1;
		param->zoom *= 1.2;
		if (param->plus < 16)
		 	param->move_x -= 0.25;
		param->move_x -= (0.15 / param->plus);
		draw_fract(param);
	}
	if (button == 78)
	{
		if (param->zoom > 197)
			return (0);
		param->zoom /= 1.2;
		draw_fract(param);
	}
	if (button == 124)
	{
		param->move_x += 0.1;
		draw_fract(param);
	}
	if (button == 123)
	{
		param->move_x -= 0.1;
		draw_fract(param);
	}
	if (button == 126)
	{
		param->move_y -= 0.1;
		draw_fract(param);
	}
	if (button == 125)
	{
		param->move_y += 0.1;
		draw_fract(param);
	}
	return (0);
}

int			mouse_zoom(int button, int x, int y, t_param *param)
{
	if (x < 0 || x > param->w || y < 0 || y > param->h)
		return (0);
	if (button == 5)
	{
		if (param->zoom > 197)
			return (0);
		param->plus *= 2.1;
		param->zoom *= 1.2;
		if (param->plus < 16)
		 	param->move_x -= 0.25;
		param->move_x -= (0.15 / param->plus);
		draw_fract(param);
	}
	if (button == 4)
	{
		param->zoom /= 1.2;
		draw_fract(param);
	}
	return (0);
}

int 	mouse_move(int x, int y, t_param *param)
{
	if (x < param->w && x > 0 && y < param->h && y >0)
	{
		param->cRe_s = 1.5 * (x - param-> w / 2) / (0.5 * param->w);
		param->cIm_s = (y - param->h / 2) / (0.5 * param->h);
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