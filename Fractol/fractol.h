/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 01:24:43 by drestles          #+#    #+#             */
/*   Updated: 2019/01/11 00:34:48 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_mb {
	int		x;
	int		y;
	int		i;
	float	pr;
	float	pi;
	float	new_re;
	float	new_im;
	float	old_re;
	float	old_im;

}				t_mandelbrot;

typedef struct	s_param {
	int			fractal;
	float		zoom;
	void		*mlx_ptr;
	void		*win_ptr;
	int			w;
	int			h;
	void		*image;
	char		*data;
	int			bpp;
	int			s_l;
	int			end;
	int			color;
	int			color_s;
	int			plus;
	int			max_iterations;
	float		cre_s;
	float		cim_s;
	float		x_0;
	float		y_0;
}				t_param;

int				ft_strcmp(const char *s1, const char *s2);
void			pixel_to_img(t_param *f, int x, int y);
void			draw_pixels(t_mandelbrot *mb, t_param *param);
void			mandel_param(t_mandelbrot *mb, t_param *param);
void			mandel(t_param *param);
void			julia_param(t_mandelbrot *mb, t_param *param);
void			julia(t_param *param);
int				draw_fract(t_param *param);
int				mouse_zoom(int button, int x, int y, t_param *param);
int				key_button(int button, t_param *param);
void			julia_param(t_mandelbrot *mb, t_param *param);
void			julia(t_param *param);
float			abs_f(float a);
void			b_s(t_param *param);
void			init_mlx(t_param *param);

#endif
