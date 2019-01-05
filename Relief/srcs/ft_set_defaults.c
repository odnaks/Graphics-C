/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_defaults.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 11:01:14 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 11:01:15 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void			ft_set_minmax_y(int *miny, int *maxy, t_params *params)
{
	t_list		*temp;
	t_point3d	*point;

	temp = params->points;
	*miny = ((t_point3d *)(temp->content))->yi;
	*maxy = *miny;
	while (temp)
	{
		point = (t_point3d *)(temp->content);
		if ((point->yi) < (*miny))
			(*miny) = point->yi;
		if ((point->yi) > (*maxy))
			(*maxy) = point->yi;
		temp = temp->next;
	}
}

static void			ft_set_minmax(int **minmax, t_params *params)
{
	t_list		*temp;
	t_point3d	*point;

	temp = params->points;
	while (temp)
	{
		point = (t_point3d *)(temp->content);
		if ((point->x) < (*(minmax))[MINX])
			(*(minmax))[MINX] = point->x;
		if ((point->x) > (*(minmax))[MAXX])
			(*(minmax))[MAXX] = point->x;
		if ((point->y) < (*(minmax))[MINY])
			(*(minmax))[MINY] = point->y;
		if ((point->y) > (*(minmax))[MAXY])
			(*(minmax))[MAXY] = point->y;
		temp = temp->next;
	}
}

void				ft_set_start_settings_iso(t_params *params)
{
	int	miny;
	int	maxy;

	params->c.type = P_ISO;
	ft_apply_correction(params->c, params);
	ft_set_minmax_y(&miny, &maxy, params);
	params->c.sc[P_ISO] = ((double)params->height / 2) / (maxy - miny);
	ft_apply_correction(params->c, params);
	ft_set_minmax_y(&miny, &maxy, params);
	params->c.mv[P_ISO].z = (double)(maxy + miny) / 2;
}

void				ft_set_start_settings_par(t_params *params)
{
	int			*minmax;
	t_point3d	*point;

	minmax = (int *)malloc(4 * sizeof(int));
	point = (t_point3d *)params->points->content;
	minmax[MINX] = point->x;
	minmax[MAXX] = point->x;
	minmax[MINY] = point->y;
	minmax[MAXY] = point->y;
	ft_set_minmax(&minmax, params);
	params->c.sc[P_PAR] =
		(((double)params->height) / 2) / (minmax[MAXY] - minmax[MINY]);
	params->c.sc[P_PAR] = (((double)params->width / 2) /
		(minmax[MAXX] - minmax[MINX]) > params->c.sc[P_PAR]) ?
		params->c.sc[P_PAR] : (((double)params->width / 2) /
		(minmax[MAXX] - minmax[MINX]));
	minmax[MINX] = (int)(minmax[MINX] * params->c.sc[P_PAR]);
	minmax[MAXX] = (int)(minmax[MAXX] * params->c.sc[P_PAR]);
	minmax[MINY] = (int)(minmax[MINY] * params->c.sc[P_PAR]);
	minmax[MAXY] = (int)(minmax[MAXY] * params->c.sc[P_PAR]);
	params->c.mv[P_PAR].x = (double)(-minmax[MAXX] + minmax[MINX]) / 2;
	params->c.mv[P_PAR].y = (double)(-minmax[MAXY] + minmax[MINY]) / 2;
	free(minmax);
}

void				ft_set_start_settings_con(t_params *params)
{
	int			*minmax;
	t_point3d	*point;

	minmax = (int *)malloc(4 * sizeof(int));
	point = (t_point3d *)params->points->content;
	minmax[MINX] = point->x;
	minmax[MAXX] = point->x;
	minmax[MINY] = point->y;
	minmax[MAXY] = point->y;
	ft_set_minmax(&minmax, params);
	params->c.sc[P_CON] =
		(((double)params->height) / 2) / (minmax[MAXY] - minmax[MINY]);
	params->c.sc[P_CON] = (((double)params->width / 2) /
		(minmax[MAXX] - minmax[MINX]) > params->c.sc[P_CON]) ?
		params->c.sc[P_CON] : (((double)params->width / 2) /
		(minmax[MAXX] - minmax[MINX]));
	minmax[MINX] = (int)(minmax[MINX] * params->c.sc[P_CON]);
	minmax[MAXX] = (int)(minmax[MAXX] * params->c.sc[P_CON]);
	minmax[MINY] = (int)(minmax[MINY] * params->c.sc[P_CON]);
	minmax[MAXY] = (int)(minmax[MAXY] * params->c.sc[P_CON]);
	params->c.mv[P_CON].x = (double)(-minmax[MAXX] + minmax[MINX]) / 2;
	params->c.mv[P_CON].y = (double)(-minmax[MAXY] + minmax[MINY]) / 2;
	free(minmax);
}
