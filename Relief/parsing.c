/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 02:42:48 by drestles          #+#    #+#             */
/*   Updated: 2018/12/14 22:40:55 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
/*
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
*/

int     check_size(t_list *lst, t_fdf *fdf)
{
    int i;
    char **split;

    fdf->max_x = -1;
    fdf->max_y = 0;
    while (lst)
    {
    	i = 0;
    	split = *((char ***)(lst->content));
		(fdf->max_y)++;
        while (split[i])
		{
        	i++;
		}
		fdf->max_x = (fdf->max_x == -1) ? i : fdf->max_x;
        if (fdf->max_x != i)
			return (1);
        lst = lst->next;
    }
	return (0);
}

void	lst_del(void *content, size_t content_size)
{
	char **split;
	int	i;

	if (content_size)
	{
		i = 0;
		split = *(char ***)content;
		while(split[i])
			free(split[i++]);
		free(split);
	}
	free(content);
}

int ft_malloc_matrix(int ***matrix, size_t ***matrixc, int x, int y)
{
	int i;
	int j;

	if (!(*matrix = (int **)malloc(y * sizeof(int *))) || (i = 0))
		return (1);
	(!(*matrixc = (size_t **)malloc(y* sizeof(size_t *)))) ? free(*matrix) : (void)0;
	if (!(*matrixc) || (j = 0))
		return (!(*matrix = 0x0));
	while (i < x)
	{
		if (!((*matrix)[i++] = (int *)malloc(x * sizeof(int))) ||
			!((*matrixc)[j++] = (size_t *)malloc(x * sizeof(size_t))))
		{
			(i == j) ? free((*matrix)[i--]) : (void)0;
			while (i--)
				free((*matrix)[i]);
			while (j--)
				free((*matrixc)[j]);
			free(*matrix);
			free(*matrixc);
			*matrix = 0x0;
			return (!(*matrixc = 0x0));
		}
	}
	return (0);
}

int 	ft_read_color(char *str, size_t *color)
{
	int		i;
	size_t	result;

	if ((str[0] != '0') || ((str[1] != 'x') && (str[1] != 'X')) || (ft_strlen(str)!=8))
		return (1);
	i = 1;
	result = 0;
	while (i++ < 7)
	{
		if ((str[i] <='F' && str[i] >= 'A') || ft_isdigit(str[i]))
		{
			result *= 16;
			result += (ft_isdigit(str[i]) ? (str[i] - '0') : (str[i]-'A'+10));
		}
		else
			return (1);
	}
	*color = result;
	return (0);
}

int		ft_fill_matrix(t_fdf *fdf, t_list *lst)
{
	int i;
	int j;
	char **split;
	int comma;
	char *itoa;

	i = 0;
	while (lst)
	{
		j = 0;
		split = *(char ***)((lst)->content);
		while (split[j])
		{
			comma = ft_strchr(split[j], ',') ? (int) (ft_strchr(split[j], ',') - split[j]) : -1;
			if (comma == -1)
			{
				itoa = ft_itoa(ft_atoi(split[j]));
				if (ft_strequ(split[j], itoa))
					(fdf->matrix)[i][j] = ft_atoi(itoa);
				else
					return (1);
				(fdf->matrixc)[i][j] = 0;
			}
			else
			{
				itoa = ft_itoa(ft_atoi(split[j]));
				if (ft_strnequ(split[j], itoa, ft_strlen(itoa)))
					(fdf->matrix)[i][j] = ft_atoi(itoa);
				else
					return (1);
				if (ft_read_color((split[j])+comma+1, &((fdf->matrixc)[i][j])))
					return (1);
			}
			j++;
		}
		i++;
		lst = lst->next;
	}
	return (0);
}

void	parsing(int fd, t_fdf *fdf)
{
	int		i;
	char	*line;
	char	**split;
	t_list	*lst;

	lst = 0x0;
	split = 0x0;
	while (ft_gnl(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		ft_lstradd(&lst, ft_lstnew(&split, sizeof(&split)));
		i = 0;
	}
	ft_putendl("gnl finished");
	if (!(check_size(lst, fdf)) &&
	!(ft_malloc_matrix(&(fdf->matrix), &(fdf->matrixc), fdf->max_x, fdf->max_y)))
	{
		ft_putendl("malloc done");
		if (ft_fill_matrix(fdf, lst))
		{
			i = 0;
			while (i < fdf->max_y)
			{
				free(fdf->matrix[i]);
				free(fdf->matrixc[i++]);
			}
			free(fdf->matrix);
			free(fdf->matrixc);
		}
	}
	ft_lstdel(&lst, lst_del);
}

/*
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
	while (ft_gnl(fd, &n_line) == 1 && a < fdf->max_y)
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
}*/