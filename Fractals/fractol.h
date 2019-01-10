/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 01:24:43 by drestles          #+#    #+#             */
/*   Updated: 2019/01/10 06:43:03 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

/*  
fractal

1 julia
2 mand
3 ship
*/

typedef struct	s_mb {
	int		x;
	int		y;
	int		i;
	float	pr;
	float	pi; 
	float	newRe;
	float	newIm;
	float	oldRe;
	float	oldIm; 

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
	float		move_x;
	float		movemove_x;
	float		move_y;
	int			plus;
	int			maxIterations;
	float		cRe_s;
	float		cIm_s;
}				t_param;

//liba
int		ft_strcmp(const char *s1, const char *s2);


//mandelbrot

void	pixel_to_img(t_param *f, int x, int y);
void	draw_pixels(t_mandelbrot *mb, t_param *param);
void	mandel_param(t_mandelbrot *mb, t_param *param);
void	mandel(t_param *param);

void	julia_param(t_mandelbrot *mb, t_param *param);
void	julia(t_param *param);

int		draw_fract(t_param *param);

//loop
int			mouse_zoom(int button, int x, int y, t_param *param);
int			key_button(int button, t_param *param);

//julia
void	julia_param(t_mandelbrot *mb, t_param *param);
void	julia(t_param *param);

float	abs_f(float a);
void	b_s(t_param *param);

#endif
