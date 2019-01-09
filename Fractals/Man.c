#include "mlx.h"

//printf
#include <stdio.h>

//exit
#include "stdlib.h"

//threads
#include <pthread.h>

typedef struct	s_param {
	float		zoom;
	void		*mlx_ptr;
	void		*win_ptr;
	int			w;
	int 		h;
	void 		*image;
	char		*data;
	int			bpp;
	int 		s_l;
	int 		end;
	int 		color;
	float		move_x;
	float		movemove_x;
	float		move_y;
	int 		plus;
}				t_param;

void		pixel_to_img(t_param *f, int x, int y)
{
	if (x >= 0 && x < f->w && y >= 0 && y < f->h)
		*(unsigned int*)(f->data + (x * (f->bpp)) + (y * f->s_l)) = f->color;
}

void	drawfr(t_param *param)
{
	int		x;
	int		y;
	int		i;
	float	pr, pi; 
	float	newRe, newIm, oldRe, oldIm; 
	int		maxIterations = 300;

	y = 0;
	while (y < param->h)
	{
		x = 0;
		while (x < param->w)
		{
			pr = 1.5 * (x - param->w / 2) / (0.5 * param->zoom * param->w) + param->move_x;
			pi = (y - param->h / 2) / (0.5 * param->zoom * param->h) + param->move_y;
			//printf("(%f, %f)\n", pr, pi);
			newRe = newIm = oldRe = oldIm = 0;
			i = 0;
			while (i < maxIterations)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 16) break;
					i++;
			}
			if (i < maxIterations)
			{
 				param->color = 0x340000 - 10000 * (i % 8);
				pixel_to_img (param, x, y);

			}
			else
			{
				param->color = 0x000000;
				pixel_to_img (param, x, y);
			}
			x++;
		}
		y++;
	}

	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_put_image_to_window (param->mlx_ptr, param->win_ptr, param->image, 0, 0);	
}
 

int	key_button(int button, t_param *param)
{
	if (button == 53)
		exit(1);
	if (button == 69)
	{
		if (param->zoom > 197)
			return (0);
		param->plus *= 2.1;
		param->zoom *= 1.2;
		if (param->plus < 16)
		 	param->move_x -= 0.25;
		param->move_x -= (0.15 / param->plus);
		drawfr(param);
	}
	if (button == 78)
	{
		if (param->zoom > 197)
			return (0);
		param->zoom /= 1.2;
		drawfr(param);
	}
	if (button == 124)
	{
		param->move_x += 0.1;
		drawfr(param);
	}
	if (button == 123)
	{
		param->move_x -= 0.1;
		drawfr(param);
	}
	if (button == 126)
	{
		param->move_y -= 0.1;
		drawfr(param);
	}
	if (button == 125)
	{
		param->move_y += 0.1;
		drawfr(param);
	}
	return (0);
}

int		exit_x()
{
	exit(1);
}

int			mouse_zoom(int button, int x, int y, t_param *param)
{
	if (x < 0 || x > param->w || y < 0 || y > param->h)
		return (0);
	//printf("%d\n", button);
	if (button == 5)
	{
		if (param->zoom > 197)
			return (0);
		param->plus *= 2.1;
		param->zoom *= 1.2;
		if (param->plus < 16)
		 	param->move_x -= 0.25;
		param->move_x -= (0.15 / param->plus);
		drawfr(param);
	}
	if (button == 4)
	{
		param->zoom /= 1.2;
		drawfr(param);
	}
	return (0);
}

/* Первый параметр этой функции представляет собой указатель на переменную типа pthread_t,
которая служит идентификатором создаваемого потока. Второй параметр, указатель на переменную
типа pthread_attr_t, используется для передачи атрибутов потока.
Третьим параметром функции pthread_create() должен быть адрес функции потока.
Эта функция играет для потока ту же роль, что функция main() – для главной программы.
Четвертый параметр функции pthread_create() имеет тип void *. Этот параметр может
использоваться для передачи значения, возвращаемого функцией потока. Вскоре после
вызова pthread_create() функция потока будет запущена на выполнение параллельно с
другими потоками программы.

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);


//thread function
void	*func_name(void *arg)
{

} */

int		main()
{
	t_param param;

	param.zoom = 1;
	param.h = 500;
	param.w = 500;
	param.move_x = 0;
	param.move_y = 0;
	param.plus = 1;

	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.w, param.h, "fract'ol");
	param.image = mlx_new_image(param.mlx_ptr, param.w = 500, param.h = 500);
	param.data = mlx_get_data_addr (param.image, &param.bpp, &param.s_l, &param.end);
	param.bpp /= 8;
	param.move_x = -0.5;

	int		x;
	int		y;
	int		i;
	float	pr, pi; 
	float	newRe, newIm, oldRe, oldIm; 
	float	zoom = 1, moveX = -0.5, moveY = 0; 
	int		maxIterations = 300;

	y = 0;
	while (y < param.h)
	{
		x = 0;
		while (x < param.w)
		{
			pr = 1.5 * (x - param.w / 2) / (0.5 * zoom * param.w) + moveX;
			pi = (y - param.h / 2) / (0.5 * zoom * param.h) + moveY;
			//printf("(%f, %f)\n", pr, pi);
			newRe = newIm = oldRe = oldIm = 0;
			i = 0;
			while (i < maxIterations)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 16) break;
					i++;
			}
			if (i < maxIterations)
				mlx_pixel_put(param.mlx_ptr, param.win_ptr, x, y, 0x340000 - 10000 * (i % 8));
			else
				mlx_pixel_put(param.mlx_ptr, param.win_ptr, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_hook(param.win_ptr, 2, 0, key_button, &param);
	mlx_hook(param.win_ptr, 4, 0, mouse_zoom, &param);
	
	mlx_loop(param.mlx_ptr);
	return 0;
}