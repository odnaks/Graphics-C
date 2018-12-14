/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 02:57:53 by drestles          #+#    #+#             */
/*   Updated: 2018/12/14 17:54:58 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int exit_x(void)
{
    exit(1);
}

void		pixel_to_img(t_fdf *f, int x, int y)
{
	if (x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y)
			*(unsigned int*)(f->data + (x * (f->bpp)) + (y * f->s_l)) = f->col;
}

void		n_image(t_fdf *fdf)
{
	fdf->image = mlx_new_image(fdf->mlx, MAX_X, MAX_Y);
	fdf->data = mlx_get_data_addr(fdf->image, &fdf->bpp, &fdf->s_l, &fdf->endian);
	if (fdf->data == NULL)
		error_system();
	fdf->bpp /= 8;
}

void		ini_mlx(t_fdf *fdf)
{
	//fdf->ha = 0;
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, MAX_X, MAX_Y, "fdf");
	n_image(fdf);
}