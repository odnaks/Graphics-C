/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:39:08 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 09:39:09 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	gr_draw_image(t_params *params)
{
	t_list	*temp;

	temp = params->lines;
	while (temp)
	{
		gr_draw_line(params, *(((t_line *)temp->content)->a),
				*(((t_line *)temp->content)->b));
		temp = temp->next;
	}
}
