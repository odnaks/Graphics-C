/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 11:19:48 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/30 11:28:29 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INT_H
# define MLX_INT_H
# include <OpenGL/OpenGL.h>

# define MAX_EVENT 32
# define MAX_PIXEL_NB 200000
# define UNIQ_BPP 4

# define FONT_WIDTH 10
# define FONT_HEIGHT 20

typedef int		(*func_t)();

typedef struct	glsl_info_s
{
	GLuint	pixel_vshader;
	GLuint	pixel_fshader;
	GLuint	pixel_program;
	GLint		loc_pixel_position;
	GLint		loc_pixel_texture;
	GLint		loc_pixel_winhalfsize;

	GLuint	image_vshader;
	GLuint	image_fshader;
	GLuint	image_program;
	GLint		loc_image_position;
	GLint		loc_image_winhalfsize;
	GLint		loc_image_texture;
	GLint		loc_image_pos;
	GLint		loc_image_size;

	GLuint	font_vshader;
	GLuint	font_fshader;
	GLuint	font_program;
	GLint		loc_font_position;
	GLint		loc_font_winhalfsize;
	GLint		loc_font_texture;
	GLint		loc_font_color;
	GLint		loc_font_posinwin;
	GLint		loc_font_posinatlas;
	GLint		loc_font_atlassize;
}				glsl_info_t;

typedef struct	mlx_img_list_s
{
	int						width;
	int						height;
	char					*buffer;
	GLfloat					vertexes[8];
	struct mlx_img_list_s	*next;
}				mlx_img_list_t;

typedef struct	mlx_img_ctx_s
{
	GLuint					texture;
	GLuint					vbuffer;
	mlx_img_list_t			*img;
	struct mlx_img_ctx_s	*next;
}				mlx_img_ctx_t;

typedef struct	mlx_win_list_s
{
	void					*winid;
	mlx_img_ctx_t			*img_list;
	int						nb_flush;
	int						pixmgt;
	struct mlx_win_list_s	*next;
}				mlx_win_list_t;

typedef struct	mlx_ptr_s
{
	void				*appid;
	mlx_win_list_t		*win_list;
	mlx_img_list_t		*img_list;
	void				(*loop_hook)(void *);
	void				*loop_hook_data;
	void				*loop_timer;
	mlx_img_list_t		*font;
	int					main_loop_active;
}				mlx_ptr_t;

#endif
