//
// Created by Tsun Rhogoro on 23/11/2018.
//


#include "libft.h"
#include "fdf.h"

static void	scale_one(t_list *elem, void *xyz)
{
	t_point3d *point;
	t_xyz *params;

	params = (t_xyz *)xyz;
	point = (t_point3d *)(elem->content);
	point->x *= params->x;
	point->y *= params->y;
	point->z *= params->z;
}

void		ft_apply_scale(t_list *matrix, void *params)
{
	ft_lstforeach(matrix,params,scale_one);
}