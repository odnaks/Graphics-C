/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_draw_line_easy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:39:17 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 09:39:18 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static void		plot(int x, int y, int c, t_params *params)
{
	x = (params->width / 2) + x;
	y = (params->height / 2) + y;
	if (x > 0 && x <= params->width && y >= Y0 && y < params->height)
	{
		mlx_pixel_put(params->mlx, params->win, x, y, c);
	}
}

int				ft_math_abs(int value)
{
	return (value < 0 ? -value : value);
}

void			gr_draw_line_x(t_params *params, t_point3d pt_a, t_point3d pt_b)
{
	int		vars[6];
	double	percent1;
	double	percent2;

	percent1 = 100 - (double)((pt_a.color / 256) & 0xFF) * 100 / 255;
	percent2 = 100 - (double)((pt_b.color / 256) & 0xFF) * 100 / 255;
	vars[V_DLT] = ft_math_abs(pt_b.xi - pt_a.xi);
	vars[V_DLT_E] = ft_math_abs(pt_b.yi - pt_a.yi);
	vars[V_ERR] = 0;
	vars[V_DIR] = (pt_b.yi > pt_a.yi) ? 1 : -1;
	(pt_b.yi == pt_a.yi) ? vars[V_DIR] = 0 : (void)0;
	vars[V_X] = pt_a.xi - 1;
	vars[V_Y] = pt_a.yi;
	while (++vars[V_X] <= pt_b.xi)
	{
		plot(vars[V_X], vars[V_Y], vars[V_DLT] ? gr_color_grad(
			((double)vars[V_X] - pt_a.xi) / vars[V_DLT], percent1, percent2) :
			gr_color(percent1), params);
		vars[V_ERR] = vars[V_ERR] + vars[V_DLT_E];
		if (2 * vars[V_ERR] >= vars[V_DLT])
		{
			vars[V_Y] += vars[V_DIR];
			vars[V_ERR] -= vars[V_DLT];
		}
	}
}

void			gr_draw_line_y(t_params *params, t_point3d pt_a, t_point3d pt_b)
{
	int		vars[6];
	double	percent1;
	double	percent2;

	percent1 = 100 - (double)((pt_a.color / 256) & 0xFF) * 100 / 255;
	percent2 = 100 - (double)((pt_b.color / 256) & 0xFF) * 100 / 255;
	vars[V_DLT] = ft_math_abs(pt_b.yi - pt_a.yi);
	vars[V_DLT_E] = ft_math_abs(pt_b.xi - pt_a.xi);
	vars[V_ERR] = 0;
	vars[V_DIR] = (pt_b.xi > pt_a.xi) ? 1 : -1;
	(pt_b.xi == pt_a.xi) ? vars[V_DIR] = 0 : (void)0;
	vars[V_X] = pt_a.xi;
	vars[V_Y] = pt_a.yi - 1;
	while (++vars[V_Y] <= pt_b.yi)
	{
		plot(vars[V_X], vars[V_Y], vars[V_DLT] ? gr_color_grad(
			((double)vars[V_Y] - pt_a.yi) / vars[V_DLT], percent1, percent2) :
			gr_color(percent1), params);
		vars[V_ERR] = vars[V_ERR] + vars[V_DLT_E];
		if (2 * vars[V_ERR] >= vars[V_DLT])
		{
			vars[V_X] += vars[V_DIR];
			vars[V_ERR] -= vars[V_DLT];
		}
	}
}

void			gr_draw_line(t_params *params, t_point3d pt_a, t_point3d pt_b)
{
	if ((ft_math_abs(pt_a.xi - pt_b.xi)) < (ft_math_abs(pt_a.yi - pt_b.yi)))
		pt_a.yi < pt_b.yi ? gr_draw_line_y(params, pt_a, pt_b) :
		gr_draw_line_y(params, pt_b, pt_a);
	else
		pt_a.xi < pt_b.xi ? gr_draw_line_x(params, pt_a, pt_b) :
		gr_draw_line_x(params, pt_b, pt_a);
}
