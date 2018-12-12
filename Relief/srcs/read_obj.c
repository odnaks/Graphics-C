#include "error.h"
#include "get_next_line.h"
#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

void	clr_str_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int 	convert_line(t_list **result, char *line, int *count)
{
	char **split;
	int i;
	t_point3d *new;
	int y;

	y = (*count ? ft_lstlen(*result)/(*count) : 0);
	if (!(new = (t_point3d *)malloc(sizeof(t_point3d))))
		return (error(E_MEMORY_ERROR));
	if (!(split = ft_strsplit(line,' ')))
	{
		free(new);
		return (error(E_MEMORY_ERROR));
	}
	i = 0;
	new->right = 0x0;
	new->left = 0x0;
	new->up = 0x0;
	new->down = 0x0;
	while(split[i])
	{
		if (ft_strcmp(split[i],ft_itoa(ft_atoi(split[i]))))
		{
			clr_str_arr(split);
			free(new);
			return (error(E_WRONG_DATA));
		}
		new->z = (float)ft_atoi(split[i]);
		new->x = (float)i;
		new->y = y;
		ft_lstadd(result, ft_lstnew(new, sizeof(t_point3d)));
		i++;
	}
	clr_str_arr(split);
	free(new);
	if (*count)
	{
		if (*count != i)
			return (error(E_WRONG_DATA));
		else
			return (error(E_SUCCESS));
	}
	*count = i;
	return (E_SUCCESS);
}

t_list	*find_point(t_list *matrix, int x, int y)
{
	t_point3d *point;

	while (matrix)
	{
		point = (t_point3d *)matrix->content;
		if ((point->x == x) && (point->y == y))
			return (matrix);
		matrix = matrix->next;
	}
	return (0x0);
}

void	link_matrix(t_list *matrix, int col)
{
	int row;
	int x;
	int y;
	t_point3d *point;

	row = ft_lstlen(matrix)/col;
	x = 0;
	while (x<col-1)
	{
		y = 0;
		while (y < row - 1)
		{
			point = (t_point3d *)(find_point(matrix, x, y)->content);
			point->right =(t_point3d *)(find_point(matrix, x + 1, y)->content);
			point->down = (t_point3d *)(find_point(matrix, x, y + 1)->content);
			point->right->left = point;
			point->down->up = point;
			y++;
		}
		x++;
	}
}

int read_obj(char *file, t_list **matrix)
{
	int fd;
	char *line;
	int gnl;
	int count;

	fd = open(file, O_RDWR);
	if (fd < 0)
		return (error(E_READING_ERROR));
	matrix = 0x0;
	count = 0;
	while((gnl = get_next_line(fd, &line))>0)
	{
		if (convert_line(matrix,line,&count))
			return (error(E_ERROR));
		free(line);
	}
	if (gnl<0)
		return (error(E_READING_ERROR));
	link_matrix(*matrix, count);
	return (E_SUCCESS);
}