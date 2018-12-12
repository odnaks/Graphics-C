//
// Created by Tsun Rhogoro on 23/11/2018.
//

#include <math.h>
#include "libft.h"
#include "fdf.h"

static void	calculate_rotation(double *x, double *y, double angle)
{
	double sqrt_xy;

	if ((*x != 0) || (*y !=0))
	{
		angle = M_PI * angle / 360;
		if (*y == 0)
			angle += (*x > 0) ? 0 : M_PI_2;
		else
			angle += atan(*x / *y);
		sqrt_xy = sqrt(*x * *x + *y * *y);
		*x = (sqrt_xy * sin(angle));
		*y = (sqrt_xy * cos(angle));
	}
}

static void	rotate_one(t_list *elem, void *xyz)
{
	t_point3d *point;
	t_xyz *params;
	double angle;

	params = (t_xyz *)xyz;
	point = (t_point3d *)(elem->content);
	if (params->x)
		calculate_rotation(&point->y, &point->z, params->x);
	if (params->y)
		calculate_rotation(&point->z, &point->x, params->y);
	if (params->z)
		calculate_rotation(&point->x, &point->y, params->z);
}

void		ft_apply_rotation(t_list *matrix, void *params)
{
	ft_lstforeach(matrix,params,rotate_one);
}
