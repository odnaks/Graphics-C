/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 10:27:55 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 10:27:56 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int			p_eq(void *elem1, void *elem2)
{
	t_point3d	*point1;
	t_point3d	*point2;

	point1 = (t_point3d *)elem1;
	point2 = (t_point3d *)elem2;
	if ((point1->x == point2->x) && (point1->y == point2->y))
		return (1);
	return (0);
}

void		clr_str_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int			exit_x(void)
{
	exit(1);
}
