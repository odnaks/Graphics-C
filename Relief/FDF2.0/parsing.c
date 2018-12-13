/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 02:42:48 by drestles          #+#    #+#             */
/*   Updated: 2018/12/13 07:20:28 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void		free_split(char **tab, int max)
{
	int		a;

	a = 0;
	while (tab[a] && a < max)
		free(tab[a++]);
	free(tab);
}

int			fill_coord_value(char *str, int *max)
{
	int nbr;

	nbr = 0;
	if (*str && *str == '0')
		nbr = 0;
	else if (*str && *str > '0' && *str <= '9')
	{
		nbr = ft_atoi(&(*str));
		if (abs(nbr) > *max)
			*max = abs(nbr);
	}
	return (nbr);
}

int			*fill_line(char **split, int max_x, int *max_z)
{
	int		a;
	int		*tab;

	tab = NULL;
	a = 0;
	if ((tab = (int *)malloc(sizeof(int) * max_x)) == NULL)
		error_system();
	while (split[a] && a < max_x)
	{
		tab[a] = fill_coord_value(split[a], max_z);
		a++;
	}
	return (tab);
}

t_fdf		*parsing(int fd, int y, t_fdf *fdf)
{
	char	*n_line;
	char	**split;
	int		a;
	int		**tab;
	int		ret;

	ret = 0;
	fdf->max_y = y;
	a = 0;
	if ((tab = (int **)malloc(sizeof(int *) * fdf->max_y)) == NULL)
		error_system();
	while (get_next_line(fd, &n_line) == 1 && a < fdf->max_y)
	{
		split = ft_strsplit(n_line, ' ');
		if (a == 0)
			while (split[ret])
				ret++;
		tab[a++] = fill_line(split, ret, &(fdf->max_z));
		free_split(split, ret);
		ft_memdel((void **)&n_line);
	}
	ft_memdel((void **)&n_line);
	fdf->matrix = tab;
	fdf->max_x = ret;
	return (fdf);
}