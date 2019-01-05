/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:37:18 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 09:37:19 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void	rotate_one(t_list *elem, void *xyz)
{
	t_point3d	*point;
	t_xyz		*params;
	double		temp;

	params = (t_xyz *)xyz;
	point = (t_point3d *)(elem->content);
	if (params->x)
	{
		temp = point->yt;
		point->yt = point->yt * cos(params->x) + point->zt * sin(params->x);
		point->zt = -temp * sin(params->x) + point->zt * cos(params->x);
	}
	if (params->y)
	{
		temp = point->xt;
		point->xt = point->xt * cos(params->y) + point->zt * sin(params->y);
		point->zt = -temp * sin(params->y) + point->zt * cos(params->y);
	}
	if (params->z)
	{
		temp = point->xt;
		point->xt = point->xt * cos(params->z) - point->yt * sin(params->z);
		point->yt = temp * sin(params->z) + point->yt * cos(params->z);
	}
}

void		ft_apply_rotation(void *params, t_params *param)
{
	ft_lstforeach(param->points, params, rotate_one);
}
