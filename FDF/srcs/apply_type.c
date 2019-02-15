/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:37:33 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 09:37:34 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	ft_apply_con(t_list *elem)
{
	t_point3d	*point3d;

	point3d = (t_point3d *)(elem->content);
	point3d->xt = point3d->xt * (CON_D + point3d->zt) / CON_D;
	point3d->yt = point3d->yt * (CON_D + point3d->zt) / CON_D;
}

static void	ft_apply_iso(t_list *elem)
{
	double		xt;
	double		yt;
	t_point3d	*p;

	p = (t_point3d *)(elem->content);
	xt = p->xt;
	yt = p->yt;
	p->xt = (xt - yt) * cos(0.523599);
	p->yt = -p->zt + (xt + yt) * sin(0.523599);
}

static void	ft_double_to_int(t_list *elem)
{
	t_point3d *point;

	point = (t_point3d *)elem->content;
	point->xi = (int)point->xt;
	point->yi = (int)point->yt;
	point->zi = (int)point->zt;
}

void		ft_apply_type(int type, t_params *params)
{
	if (type == P_ISO)
	{
		ft_lstiter(params->points, ft_apply_iso);
	}
	else if (type == P_CON)
		ft_lstiter(params->points, ft_apply_con);
	ft_lstiter(params->points, ft_double_to_int);
}
