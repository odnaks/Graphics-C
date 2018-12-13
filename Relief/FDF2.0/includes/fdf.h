/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:17:41 by drestles          #+#    #+#             */
/*   Updated: 2018/12/13 08:46:38 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include <mlx.h>

# define MAX_X	2560
# define MAX_Y	1440

typedef	struct			s_line
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	float				dx;
	float				dy;
}						t_line;


typedef struct s_fdf {

    void    *mlx;
    void    *win;

    void    *image;
    char    *data;
    int     bpp;
    int     s_l;
    int     endian;

    int     max_x;
    int     max_y;
	int		max_z;

    int     ind_x;
    int     ind_y;

    int     move_x;
    int     move_y;

    int     zoom;

	int		col;

    int     **matrix;

}              t_fdf;

//error
void	ac_error(void);
void	file_error(void);
void	bad_map(void);
void	error_system(void);

//check_valid
int         check_hex(char *line);
int			check_valid_line(char *line);
int			check_valid_file(int fd);

//parsing
void		free_split(char **tab, int max);
int			fill_coord_value(char *str, int *max);
int			*fill_line(char **split, int max_x, int *max_z);
t_fdf		*parsing(int fd, int y, t_fdf *fdf);

//window
void		pixel_to_img(t_fdf *f, int x, int y);
int         exit_x(void);
void		n_image(t_fdf *fdf);
void		ini_mlx(t_fdf *fdf);

//image


void	set_coord_hor(t_line *p, t_fdf *f, int x, int y);
void	set_coord_ver(t_line *p, t_fdf *f, int x, int y);
void	set_coord(t_fdf *fdf, int x, int y);
int		fill_img(t_fdf *f);


#endif