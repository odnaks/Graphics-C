/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:17:45 by drestles          #+#    #+#             */
/*   Updated: 2018/12/13 07:05:26 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

#include <stdio.h>

/* int scroll_up (t_fdf *fdf)
{
	fdf->move_x += 10;
	mlx_destroy_image(fdf->mlx, fdf->image);
	n_image(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	fill_img(fdf);
	return (0);
} */


void keycodes(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		exit_x();
	if (keycode == 124)
		fdf->move_x += 30;
	if (keycode == 123)
		fdf->move_x -= 30;
	if (keycode == 126)
		fdf->move_y -= 30;
	if (keycode == 125)
		fdf->move_y += 30;
	if (keycode == 69)
		fdf->zoom += 1;
	if (keycode == 78)
		if (fdf->zoom > 2)
			fdf->zoom -= 1;
}

int key_press(int keycode, t_fdf *fdf)
{
	keycodes(keycode, fdf);

	mlx_destroy_image(fdf->mlx, fdf->image);
	n_image(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	fill_img(fdf);

	return (0);
}

int			main(int ac, char **av)
{
	int		y;
	int		fd;
	t_fdf	fdf;

	//fdf.zo = 10;
	if (ac < 2 || ac >= 3)
		ac_error();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		file_error();
	y = check_valid_file(fd);
	close(fd);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		file_error();
	parsing(fd, y, &fdf);
	ini_mlx(&fdf);
	fill_img(&fdf);
	//mlx_hook(fdf.win, 2, 1, key_hook, &fdf);

	mlx_hook (fdf.win, 2, 0, key_press, &fdf);
	//mlx_hook (fdf.win, 5, 0, scroll_down, 0);
	mlx_hook (fdf.win, 17, 0, exit_x, 0);
	mlx_loop(fdf.mlx);
	return (1);
}
