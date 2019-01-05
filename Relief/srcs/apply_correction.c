/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_correction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:36:50 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 09:37:02 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_apply_correction(t_correction correction, t_params *params)
{
	ft_apply_scale(&correction.sc[correction.type], params);
	ft_apply_move(&correction.mv[correction.type], params);
	ft_apply_rotation(&correction.rt[correction.type], params);
	ft_apply_type(correction.type, params);
}
