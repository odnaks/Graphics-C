/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:32:48 by drestles          #+#    #+#             */
/*   Updated: 2018/12/13 08:04:50 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ac_error(void)
{
	ft_putstr_fd("usage: ./fdf [map_file]\n", 2);
	exit(EXIT_FAILURE);
}

void	file_error(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}

void	bad_map(void)
{
	ft_putstr_fd("error : Map invalid\n", 2);
	exit(EXIT_FAILURE);
}

void	error_system(void)
{
	ft_putstr_fd("error system\n", 2);
	exit(EXIT_FAILURE);
}
