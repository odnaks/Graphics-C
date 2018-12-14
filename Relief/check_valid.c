/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:29:42 by drestles          #+#    #+#             */
/*   Updated: 2018/12/13 21:13:43 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			check_hex(char *line)
{
	int		a;

	a = 0;
	line++;
	if (*line && *line != '0')
		bad_map();
	line++;
	if (*line && *line != 'x')
		bad_map();
	line++;
	while (*line && *line != ' ')
	{
		if ((*line < '0' || *line > '9') && (*line < 'A' || *line > 'F')
				&& (*line < 'a' || *line > 'f'))
			bad_map();
		line++;
		a++;
	}
	if (a < 2 || a > 6)
		bad_map();
	return (a);
}

int			check_valid_line(char *line)
{
	int		a;

	a = 0;
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		if (*line && *line == '-')
			line++;
		if (!*line || *line < '0' || *line > '9')
			bad_map();
		while (*line != '\0' && *line >= '0' && *line <= '9')
			line++;
		a++;
		if (*line == '\0')
			break ;
		if (*line == ',')
			line += check_hex(&(*line)) + 3;
		if (*line == '\0')
			break ;
		while (*line && *line == ' ')
			line++;
	}
	return (a);
}

int			check_valid_file(int fd)
{
	int		a;
	int		b;
	int		ret;
	char	*new_line;
	int		y;

	a = 0;
	b = 0;
	y = 0;
	while ((ret = ft_gnl(fd, &new_line)) == 1)
	{
		a = check_valid_line(new_line);
		ft_memdel((void **)&new_line);
		if (a != b && y > 0)
			bad_map();
		y++;
		b = a;
	}
	if (ret == -1)
		bad_map();
	ft_memdel((void **)&new_line);
	return (y);
}
