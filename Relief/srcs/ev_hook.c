/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:38:42 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 09:38:43 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_int.h>
#include "fdf.h"
#include "mlx.h"
#include "keys.h"
#include "stdlib.h"

void	keycodes(int keycode, t_correction *c)
{
	(keycode == KEY_ESC) ? exit(0) : (void)0;
	(keycode == KEY_Q) ? c->mv[c->type].x += MV_STEP : (void)0;
	(keycode == KEY_W) ? c->mv[c->type].x -= MV_STEP : (void)0;
	(keycode == KEY_A) ? c->mv[c->type].y += MV_STEP : (void)0;
	(keycode == KEY_S) ? c->mv[c->type].y -= MV_STEP : (void)0;
	(keycode == KEY_Z) ? c->mv[c->type].z += MV_STEP : (void)0;
	(keycode == KEY_X) ? c->mv[c->type].z -= MV_STEP : (void)0;
	(keycode == KEY_E) ? c->rt[c->type].x += RT_STEP : (void)0;
	(keycode == KEY_R) ? c->rt[c->type].x -= RT_STEP : (void)0;
	(keycode == KEY_D) ? c->rt[c->type].y += RT_STEP : (void)0;
	(keycode == KEY_F) ? c->rt[c->type].y -= RT_STEP : (void)0;
	(keycode == KEY_C) ? c->rt[c->type].z += RT_STEP : (void)0;
	(keycode == KEY_V) ? c->rt[c->type].z -= RT_STEP : (void)0;
	(keycode == KEY_NP_PLS) ? c->sc[c->type] += SC_STEP : (void)0;
	(keycode == KEY_NP_MIN) ? c->sc[c->type] -= SC_STEP : (void)0;
	(keycode == KEY_1) ? c->type = P_ISO : (void)0;
	(keycode == KEY_2) ? c->type = P_PAR : (void)0;
	(keycode == KEY_3) ? c->type = P_CON : (void)0;
}

int		key_hook(int keycode, t_params *params)
{
	keycodes(keycode, &params->c);
	mlx_clear_window(params->mlx, params->win);
	ft_print_menu(params);
	ft_apply_correction(params->c, params);
	gr_draw_image(params);
	return (0);
}
