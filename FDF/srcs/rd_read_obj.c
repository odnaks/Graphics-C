/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_read_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:39:23 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 12:13:13 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>

static int		ft_add_elements(char **split, t_point3d *new, t_params *params)
{
	int i;

	i = 0;
	while (split[i])
	{
		if (ft_strcmp(split[i], ft_itoa(ft_atoi(split[i]))))
		{
			clr_str_arr(split);
			free(new);
			return (ft_error(E_WRONG_DATA));
		}
		new->z = ft_atoi(split[i]);
		new->x = i;
		new->y = params->max_y;
		ft_lstadd(&(params->points), ft_lstnew(new, sizeof(t_point3d)));
		i++;
	}
	return (i);
}

static int		convert_line(char *line, t_params *params)
{
	char		**split;
	int			i;
	t_point3d	*new;

	if (!(new = (t_point3d *)malloc(sizeof(t_point3d))))
		return (ft_error(E_MEMORY_ERROR));
	if (!(split = ft_strsplit(line, ' ')))
	{
		free(new);
		return (ft_error(E_MEMORY_ERROR));
	}
	i = ft_add_elements(split, new, params);
	(params->max_y)++;
	clr_str_arr(split);
	free(new);
	if (params->max_x)
	{
		if (params->max_x != i)
			return (ft_error(E_WRONG_DATA));
		else
			return (E_SUCCESS);
	}
	params->max_x = i;
	return (E_SUCCESS);
}

static void		link_loop(t_params *par, t_line *l, t_point3d *f)
{
	int x;
	int y;

	x = -1;
	while (++x < par->max_x)
	{
		y = -1;
		while (++y < par->max_y)
		{
			f->x = x;
			f->y = y;
			l->a = (t_point3d *)(ft_lstfindcontent(par->points, f, p_eq));
			if ((f->x = x + 1) < par->max_x)
			{
				l->b = (t_point3d *)(ft_lstfindcontent(par->points, f, p_eq));
				ft_lstadd(&(par->lines), ft_lstnew(l, sizeof(*l)));
			}
			if ((f->y = y + 1) < par->max_y)
			{
				f->x = x;
				l->b = (t_point3d *)(ft_lstfindcontent(par->points, f, p_eq));
				ft_lstadd(&(par->lines), ft_lstnew(l, sizeof(*l)));
			}
		}
	}
}

static int		link_matrix(t_params *params)
{
	t_line		*line;
	t_point3d	*find;

	if (!(line = (t_line*)malloc(sizeof(t_line))))
		return (ft_error(E_MEMORY_ERROR));
	if (!(find = (t_point3d *)malloc(sizeof(t_list))))
	{
		free(line);
		return (ft_error(E_MEMORY_ERROR));
	}
	link_loop(params, line, find);
	free(line);
	free(find);
	return (E_SUCCESS);
}

int				read_obj(char *file, t_params *params)
{
	int		fd;
	char	*line;
	int		gnl;

	fd = open(file, O_RDWR);
	if (fd < 0)
		return (ft_error(E_READING_ERROR));
	params->max_x = 0;
	while ((gnl = ft_gnl(fd, &line)) > 0)
	{
		if (convert_line(line, params))
			return (ft_error(E_ERROR));
		free(line);
	}
	if (gnl < 0)
		return (ft_error(E_READING_ERROR));
	link_matrix(params);
	if ((params->max_x < 2) || (params->max_y < 2))
		return (ft_error(E_WRONG_DATA));
	return (E_SUCCESS);
}
