/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:38:48 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 09:38:49 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	ft_error(int error_number)
{
	if (error_number == E_MEMORY_ERROR)
		ft_putendl(M_ERR_MEM);
	if (error_number == E_WRONG_DATA)
		ft_putendl(M_ERR_DATA);
	if (error_number == E_READING_ERROR)
		ft_putendl(M_ERR_READ);
	if (error_number == E_WIDTH)
		ft_putendl(M_WIDTH);
	if (error_number == E_HEIGHT)
		ft_putendl(M_HEIGHT);
	if (error_number == E_FILE_ERR)
		ft_putendl(M_FILE_ERR);
	if (error_number != E_SUCCESS)
		exit(error_number);
	return (error_number);
}
