/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:39:38 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 09:39:39 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void		init_correction(t_correction *c, int type)
{
	int i;

	c->type = type;
	i = 0;
	while (i < 3)
	{
		c->mv[i].x = 0;
		c->mv[i].y = 0;
		c->mv[i].z = 0;
		c->rt[i].x = 0;
		c->rt[i].y = 0;
		c->rt[i].z = 0;
		c->sc[i] = 1;
		i++;
	}
}

int			ft_check_args(int argc, char **argv, t_params *params)
{
	char		*file;

	if (argc != 2 && argc != 4)
		ft_print_usage();
	if (argc == 4)
	{
		(ft_strequ(ft_itoa(ft_atoi(argv[2])), argv[2])) ?
			params->width = ft_atoi(argv[2]) : ft_print_usage();
		(ft_strequ(ft_itoa(ft_atoi(argv[3])), argv[3])) ?
			params->height = ft_atoi(argv[3]) : ft_print_usage();
		if ((params->width < MIN_WIDTH) || (params->width > MAX_WIDTH))
			ft_error(E_WIDTH);
		if ((params->height < MIN_HEIGHT) || (params->height > MAX_HEIGHT))
			ft_error(E_HEIGHT);
	}
	else
	{
		params->width = MAX_X;
		params->height = MAX_Y - Y0;
	}
	file = argv[1];
	if (read_obj(file, params) != E_SUCCESS)
		ft_error(E_FILE_ERR);
	return (E_SUCCESS);
}

int			main(int argc, char **argv)
{
	t_params	params;

	ft_check_args(argc, argv, &params);
	init_correction(&params.c, P_ISO);
	params.max_x = 0;
	params.max_y = 0;
	params.mlx = mlx_init();
	params.win = mlx_new_window(params.mlx, params.width, params.height, "fdf");
	ft_apply_color(params.points, &params);
	ft_set_start_settings_par(&params);
	ft_set_start_settings_iso(&params);
	ft_set_start_settings_con(&params);
	ft_apply_correction(params.c, &params);
	ft_print_menu(&params);
	gr_draw_image(&params);
	mlx_hook(params.win, 2, 0, key_hook, &params);
	mlx_hook(params.win, 17, 0, exit_x, 0);
	mlx_loop(params.mlx);
	return (0);
}
