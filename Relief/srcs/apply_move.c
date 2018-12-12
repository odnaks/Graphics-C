#include "libft.h"
#include "fdf.h"
#include <math.h>

static void	move_one(t_list *elem, void *xyz)
{
	t_point3d *point;
	t_xyz *params;

	params = (t_xyz *)xyz;
	point = (t_point3d *)(elem->content);
	point->x += params->x;
	point->y += params->y;
	point->z += params->z;
}

void ft_apply_move (t_list *matrix, void *params)
{
	ft_lstforeach(matrix, params, move_one);
}