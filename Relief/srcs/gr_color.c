/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:38:56 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 09:38:57 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_set_minmax_z(int *minz, int *maxz, t_params *params)
{
	t_list		*temp;
	t_point3d	*point;

	temp = params->points;
	*minz = ((t_point3d *)(temp->content))->z;
	*maxz = *minz;
	while (temp)
	{
		point = (t_point3d *)(temp->content);
		if ((point->z) < (*minz))
			(*minz) = point->z;
		if ((point->z) > (*maxz))
			(*maxz) = point->z;
		temp = temp->next;
	}
}

void			ft_apply_color(t_list *lst, void *param)
{
	t_params	*params;
	int			minz;
	int			maxz;
	t_point3d	*point;

	params = (t_params *)param;
	ft_set_minmax_z(&(params->min_z), &(params->max_z), params);
	minz = params->min_z;
	maxz = params->max_z;
	while (lst)
	{
		point = (t_point3d *)lst->content;
		point->color = gr_color(
				(100 * (double)(point->z - minz) / (maxz - minz)));
		lst = lst->next;
	}
}

int				gr_color(double percent)
{
	int green;
	int red;

	red = (int)(percent * 255 / 100);
	green = (int)((100 - percent) * 255 / 100);
	return (red * 256 * 256 + green * 256);
}

int				gr_color_grad(double percent, double percent1, double percent2)
{
	return (gr_color((int)(percent1 < percent2 ?
		percent1 + percent * (percent2 - percent1) :
		percent1 - percent * (percent1 - percent2))));
}
