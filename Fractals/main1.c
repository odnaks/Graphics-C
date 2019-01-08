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
	int			move_x;
	int			move_y;
	int 		plus;
}				t_param;

void		pixel_to_img(t_param *f, int x, int y)
{
	if (x >= 0 && x < f->w && y >= 0 && y < f->h)
		*(unsigned int*)(f->data + (x * (f->bpp)) + (y * f->s_l)) = f->color;
}

void	drawfr(t_param *param)
{
	float	zi, zr, ci, cr, tmp;
	int		i, j, k, m;
	int		DEPTH = 30;
	int		x = (param->w / 2) * param->zoom;
	float	xd = (float)x;
	int		y = (param->h / 2) * param->zoom;
	float	yd = (float)y / 1.5;

	i = -x;
	while (i < x)
	{
		ci = ((float)i) / xd;
		j = -y;
		while (j < y)
		{		
			cr = ((float)j) / yd;	
			zi = zr = 0.0;
			k = 0;
			while (k < DEPTH)
			{	
				tmp = zr*zr - zi*zi;
				zi = 2*zr*zi + ci;
				zr = tmp + cr;
				if (zr*zr + zi*zi > 4)
					break;
				k++;
			}
			if (k < DEPTH)
			{
				param->color = 0x340000 - 10000 * (k % 8);
				pixel_to_img (param, i + (param->w / 2)
				+ param->move_x, j + (param->h / 2) + param->move_y);
			}
			else
			{
					param->color = 0x000000;
					pixel_to_img (param, i + (param->w / 2) + param->move_x, j + (param->h / 2) + param->move_y);
			}
			j++;
		}
		i++;
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
		(param->plus)+=0.5;
		param->zoom += (1.1 * param->plus);
		param->move_y += (270 * param->plus);
		drawfr(param);
	}
	if (button == 78)
	{
		(param->plus)+=0.5;
		param->zoom -= (1.1 * param->plus);
		param->move_y -= (270 * param->plus);
		drawfr(param);
	}
	if (button == 124)
	{
		param->move_x -= 50;
		drawfr(param);
	}
	if (button == 123)
	{
		param->move_x += 50;
		drawfr(param);
	}
	if (button == 126)
	{
		param->move_y += 50;
		drawfr(param);
	}
	if (button == 125)
	{
		param->move_y -= 50;
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
		(param->plus)+=0.5;
		param->zoom += (1.1 * param->plus);
		param->move_y += (270 * param->plus);
		drawfr(param);
	}
	if (button == 4)
	{
		(param->plus)+=0.5;
		param->zoom -= (1.1 * param->plus);
		param->move_y -= (270 * param->plus);
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

	//pthread_create();







	t_param param;

	param.zoom = 1;
	param.h = 500;
	param.w = 500;
	param.move_x = 0;
	param.move_y = 0;
	param.plus = 1;

	int		x = (param.w / 2) * param.zoom;
	float	xd = (float)x;
	int		y = (param.h / 2) * param.zoom;
	float	yd = (float)y / 1.5;
	float zi, zr, ci, cr, tmp;
	int i, j, k, m;
	int DEPTH = 20;

	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.w, param.h, "fract'ol");
	param.image = mlx_new_image(param.mlx_ptr, param.w = 500, param.h = 500);
	param.data = mlx_get_data_addr (param.image, &param.bpp, &param.s_l, &param.end);
	param.bpp /= 8;

	i = -x;
	while (i < x)
	{
		ci = ((float)i) / xd;
		j = -y;
		while (j < y)
		{		
			cr = ((float)j) / yd;	
			zi = zr = 0.0;
			k = 0;
			while (k < DEPTH)
			{	
				tmp = zr*zr - zi*zi;
				zi = 2*zr*zi + ci;
				zr = tmp + cr;
				if (zr*zr + zi*zi > 4)
					break;
				k++;
			}
			if (k < DEPTH)
				mlx_pixel_put(param.mlx_ptr, param.win_ptr, i + x, j + y, 0x340000 - 10000 * (k % 8));
			else
				mlx_pixel_put(param.mlx_ptr, param.win_ptr, i + x, j + y, 0x000000);
			j++;
		}
		i++;
	}
  	mlx_hook(param.win_ptr, 2, 0, key_button, &param);
	mlx_hook(param.win_ptr, 4, 0, mouse_zoom, &param);
	mlx_loop(param.mlx_ptr);
	return 0;
}