/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:17:45 by drestles          #+#    #+#             */
/*   Updated: 2018/12/14 22:23:52 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

#include <stdio.h>


void init_fdf(t_fdf *fdf)
{
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->image = NULL;
	fdf->data = NULL;
	fdf->bpp = 0;
	fdf->s_l = 0;
	fdf->endian = 0;
	fdf->max_x = 0;
	fdf->max_y = 0;
	fdf->ind_x = 0;
	fdf->ind_y = 0;
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->zoom = 0;
	fdf->col = 0;
	fdf->matrix = 0x0;
	fdf->matrixc = 0x0;
}

void	print_menu(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i < 2560)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, i, 50, 0x9eff00);
		i++;
	}
	mlx_string_put(fdf->mlx, fdf->win, 30, 15, 0xfffe18, "HELP:");
	mlx_string_put(fdf->mlx, fdf->win, 230, 15, 0x9eff00, "< ^ >");
	mlx_string_put(fdf->mlx, fdf->win, 300, 15, 0x55eefe, "move");
	mlx_string_put(fdf->mlx, fdf->win, 500, 15, 0x9eff00, " + - ");
	mlx_string_put(fdf->mlx, fdf->win, 570, 15, 0x55eefe, "zoom");
}  

void	keycodes(int keycode, t_fdf *fdf)
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
	//mlx_clear_window(fdf->mlx, fdf->win);
	fill_img(fdf);
	//print_menu(fdf);

	return (0);
}

int			main(int ac, char **av)
{
	//int		y;
	int		fd;
	t_fdf	fdf;

	//fdf.zo = 10;
	if (ac < 2 || ac >= 3)
		ac_error();
//	if ((fd = open(av[1], O_RDONLY)) == -1)
//		file_error();
//	y = check_valid_file(fd);
//	close(fd);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		file_error();
	parsing(fd, &fdf);
	if (!fdf.matrix)
	ft_putendl("NULL");
	ini_mlx(&fdf);
	fill_img(&fdf);
	print_menu(&fdf);
	mlx_hook (fdf.win, 2, 0, key_press, &fdf);
	mlx_hook (fdf.win, 17, 0, exit_x, 0);
	mlx_loop(fdf.mlx);
	return (1);
}
