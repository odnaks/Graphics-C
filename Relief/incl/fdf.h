/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:39:51 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 12:06:48 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <unistd.h>

typedef struct	s_point3d
{
	int		x;
	int		y;
	int		z;
	int		xi;
	int		yi;
	int		zi;
	double	xt;
	double	yt;
	double	zt;
	int		color;
}				t_point3d;

typedef struct	s_line
{
	t_point3d *a;
	t_point3d *b;
}				t_line;

typedef struct	s_xyz
{
	double x;
	double y;
	double z;
}				t_xyz;

typedef struct	s_correction
{

	t_xyz	mv[3];
	t_xyz	rt[3];
	double	sc[3];
	int		type;
}				t_correction;

typedef struct	s_params
{
	void			*mlx;
	void			*win;
	t_correction	c;
	int				width;
	int				height;
	int				max_x;
	int				max_y;
	int				min_z;
	int				max_z;
	t_list			*points;
	t_list			*lines;
}				t_params;

# define E_SUCCESS 0
# define E_ERROR 1
# define E_MEMORY_ERROR 2
# define E_WRONG_DATA 3
# define E_READING_ERROR 4
# define E_WIDTH 5
# define E_HEIGHT 6
# define E_FILE_ERR 7

# define CON_D 500
# define P_ISO 0
# define P_PAR 1
# define P_CON 2
# define MV_STEP 10
# define RT_STEP 0.05
# define SC_STEP 0.15
# define Y0 78
# define MAX_X	4*640
# define MAX_Y	4*360
# define MINX 0
# define MAXX 1
# define MINY 2
# define MAXY 3

# define MIN_WIDTH 640
# define MAX_WIDTH 2560
# define MIN_HEIGHT 640
# define MAX_HEIGHT 1440

# define V_X 0
# define V_Y 1
# define V_ERR 2
# define V_DLT 3
# define V_DLT_E 4
# define V_DIR 5

# define M_USG "usage: ./fdf <file name> or ./fdf <file name> <width> <height>."
# define M_WIDTH "Width should be between 640 and 2560."
# define M_HEIGHT "Height should be between 640 and 1440."
# define M_FILE_ERR "File error. Please use another file."
# define M_ERR_MEM "Memory error."
# define M_ERR_DATA "Wrong data in file."
# define M_ERR_READ "Reading error."
# define HELP1 "HELP:     +   -  \t               +   -  \t Zoom:       '+'/'-'"
# define HELP2 " Move: x 'q' 'w' \t Rotation: x  'e' 'r' \t Projection: ISO '1'"
# define HELP3 "       y 'a' 's' \t           y  'd' 'f' \t             PAR '2'"
# define HELP4 "       z 'z' 'x' \t           z  'c' 'v' \t             CON '3'"

int				ft_error(int error_number);
int				read_obj(char *file, t_params *params);
int				p_eq(void *elem1, void *elem2);
void			clr_str_arr(char **arr);
void			ft_print_usage(void);
int				exit_x(void);

void			ft_set_start_settings_iso(t_params *params);
void			ft_set_start_settings_par(t_params *params);
void			ft_set_start_settings_con(t_params *params);

void			ft_apply_color(t_list *lst, void *param);
void			ft_apply_move (void *params, t_params *param);
void			ft_apply_type(int type, t_params *param);
void			ft_apply_scale(void *params, t_params *param);
void			ft_apply_rotation(void *params, t_params *param);
void			ft_apply_correction(t_correction correction, t_params *params);

void			ft_print_menu(t_params *params);
void			gr_draw_image(t_params *params);
void			gr_draw_line(t_params *params, t_point3d pt_a, t_point3d pt_b);
int				gr_color(double percent);
int				gr_color_grad(double percent, double percent1, double percent2);

int				key_hook(int keycode, t_params *param);
#endif
