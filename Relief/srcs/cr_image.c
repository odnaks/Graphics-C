//
// Created by Tsun Rhogoro on 24/11/2018.
//
#include <stdlib.h>
#include <fdf.h>
#include "libft.h"


int lst_cmp_z(t_list *elem1, t_list *elem2)
{
	t_point3d *p1;
	t_point3d *p2;

	p1 = (t_point3d *)(elem1->content);
	p2 = (t_point3d *)(elem2->content);
	if ((p1->z - p2->z) < 0)
		return (-1);
	if ((p1->z - p2->z) > 0)
		return (1);
	return (0);
}

int	init_image(char ***image2d, size_t x, size_t y)
{
	*image2d = (char **)malloc(y+1);
	(*image2d)[y] = 0x0;
	while (y-- != (size_t)(-1))
	{
		(*image2d)[y] = ft_strnew(x);
	}
}

int clear_image(char ***image2d)
{
	size_t i;

	i = 0;
	while((*image2d)[i])
		free((*image2d)[i++]);
	free(*image2d);
	*image2d = 0x0;
}

int fill_image(char **image2d, t_list *matrix3d)
{
	ft_lstsort(matrix3d, lst_cmp_z);
	/*
	 * check max and min x,y
	 *
	 */
}