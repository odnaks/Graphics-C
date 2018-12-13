/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 03:26:47 by drestles          #+#    #+#             */
/*   Updated: 2018/12/13 09:45:34 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/* static  void  iso ( int  * x ,  int  * y ,  int  z ) 
{ 
	int  previous_x ; 
	int  previous_y ;

	previous_x  =  * x ;
	previous_y  =  * y ; 
	*x  =  ( previous_x  -  previous_y )  *  cos ( 0.523599 ); 
	*y  =  - z  +  ( previous_x  +  previous_y )  *  sin ( 0.523599 ); 
} */

void	set_coord_hor(t_line *p, t_fdf *f, int x, int y)
{
	if (f->matrix[y][x] > 0)
		f->col = 0xb7c100;
	if (f->matrix[y][x] > 50)
		f->col = 0xbf2033;
	if (f->matrix[y][x] <= 0)
		f->col = 0x74b3bb;
	if (f->matrix[y][x] < -50)
		f->col = 0xfc9200;

	p->x1 = f->ind_x + ((x - y) * cos (0.523599)) * f->zoom + f->move_x;
	p->y1 = f->ind_y  + (- (f->matrix[y][x]) + (x + y) * sin (0.523599)) * f->zoom + f->move_y;

	p->x2 = f->ind_x + (((x + 1) - y) * cos (0.523599)) * f->zoom + f->move_x;
	p->y2 = f->ind_y  + (- (f->matrix[y][x + 1]) + (x + 1 + y) * sin (0.523599)) * f->zoom + f->move_y;

	p->dx = (float)(p->x2 - p->x1);
	p->dy = (float)(p->y2 - p->y1);
}

void	set_coord_ver(t_line *p, t_fdf *f, int x, int y)
{

	p->x1 = f->ind_x + ((x - y) * cos (0.523599)) * f->zoom + f->move_x;
	p->y1 = f->ind_y + (- (f->matrix[y][x]) + (x + y) * sin (0.523599)) * f->zoom + f->move_y;

	p->x2 = f->ind_x + ((x - (y + 1)) * cos (0.523599)) * f->zoom + f->move_x;
	p->y2 = f->ind_y + (- (f->matrix[y + 1][x]) + (x + 1 + y) * sin (0.523599)) * f->zoom + f->move_y;

	p->dx = (float)(p->x2 - p->x1);
	p->dy = (float)(p->y2 - p->y1);
}

void	set_coord(t_fdf *fdf, int x, int y)
{
	t_line	p;
	int		a;
	int		b;
	double	tx;

	tx = 0.0;
	if (x < fdf->max_x - 1)
		set_coord_hor(&p, fdf, x, y);
	while (tx <= 1 && x < fdf->max_x - 1)
	{
		a = p.x1 + (p.dx * tx);
		b = p.y1 + (p.dy * tx);
		pixel_to_img(fdf, a, b);
		tx += 1. / sqrt((p.dx * p.dx) + (p.dy * p.dy));
	}
	tx = 0.0;
	if (y < fdf->max_y - 1)
		set_coord_ver(&p, fdf, x, y);
	while (tx <= 1 && y < fdf->max_y - 1)
	{
		a = p.x1 + (p.dx * tx);
		b = p.y1 + (p.dy * tx);
		pixel_to_img(fdf, a, b);
		tx += 1. / sqrt((p.dx * p.dx) + (p.dy * p.dy));
	}
}

void	colors(t_fdf *f, int x, int y)
{
	f->col = 0xfc9200;
	if (f->matrix[y][x] > 0 || (x + 1 < f->max_x && f->matrix[y][x + 1] > 0))
		f->col = 0xb7c100;
	if (f->matrix[y][x] > 0 || (y + 1 < f->max_y && f->matrix[y + 1][x] > 0))
		f->col = 0xb7c100;
	if (f->matrix[y][x] <= 0 || (x + 1 < f->max_x && f->matrix[y][x + 1] <= 0))
		f->col = 0x74b3bb;
	if (f->matrix[y][x] <= 0 || (y + 1 < f->max_y && f->matrix[y + 1][x] <= 0))
		f->col = 0x74b3bb;
	if (f->matrix[y][x] < -50 || (x + 1 < f->max_x && f->matrix[y][x + 1] < -50))
		f->col = 0xfc9200;
	if (f->matrix[y][x] < -50 || (y + 1 < f->max_y && f->matrix[y + 1][x] < -50))
		f->col = 0xfc9200;
}

int		fill_img(t_fdf *f)
{
	int	x;
	int	y;
    int i;

	x = 0;
	y = 0;
	if (f->zoom == 0)
	{
   		i = 1;
    	while ((f->max_x) * i < MAX_X && (f->max_y) * i < MAX_Y && (f->max_y) * i < MAX_Y)
        	i++;
    	f->zoom = i / 3;
	}
	f->ind_x = ((MAX_X / 2) - (f->max_x * f->zoom) / 2) / (sqrt(3)/2);
	f->ind_y = (MAX_Y / 2) - (f->max_y * f->zoom) / 2;
	while (y < f->max_y)
	{
		while (x < f->max_x)
		{
			set_coord(f, x, y);
			colors(f, x, y);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->image, 0, 0);
	return (1);
}
