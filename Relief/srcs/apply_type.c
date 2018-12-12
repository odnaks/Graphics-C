#include "libft.h"
#include "fdf.h"
#include <math.h>



static void ft_apply_con(t_list *elem)
{
	t_point3d *point3d;

	point3d = (t_point3d *)(elem->content);
	point3d->x = point3d->x * (CON_D + point3d->z) / CON_D;
	point3d->y = point3d->y * (CON_D + point3d->z) / CON_D;
}

static void ft_apply_iso(t_list *elem, void *r)
{
	double x;
	double y;
	t_point3d *p;

	p = (t_point3d *)(elem->content);
	x = p->x * cos(M_PI / 6) - p->y * cos(M_PI / 6);
	y = p->z - p->x * sin(M_PI / 6) - p->y * sin(M_PI / 6);
	p->z = fabs(p->x + p->y - *(double *)r)/sqrt(2);
	p->x = x;
	p->y = y;
}

static double max_r(t_list *matrix)
{
	double r;
	t_point3d *point;
	double new_r;

	r = (double)MIN_R;
	while(matrix)
	{
		point = (t_point3d *)(matrix->content);
		if ((point->x >= 0) && (point->y >= 0))
			new_r = sqrt(point->x * point->x + point->y * point->y);
		else if ((point->x < 0) && (point->y >= 0))
			new_r = point->y;
		else if ((point->x >= 0) && (point->y < 0))
			new_r = point->x;
		else
			new_r = -sqrt(point->x * point->x + point->y * point->y);
		r = ( new_r > r ? new_r : r);
	}
	return (r);
}

void		ft_apply_type(t_list *matrix, int type)
{
	double r;

	if (type == P_ISO)
	{
		r =  max_r(matrix);
		ft_lstforeach(matrix, &r, ft_apply_iso);
	}
	else if (type == P_CON)
		ft_lstiter(matrix, ft_apply_con);
}