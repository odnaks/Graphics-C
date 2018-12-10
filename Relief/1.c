#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int exit_x(void)
{
    exit(1);
}

int  mouse_move (int  x, int  y, t_win  *param )
{
	if ((*param).press_32)
		mlx_pixel_put((*param).mlx, (*param).win, x, y, 0xffea47);
	return (0);
}

int	key_press(int keycode, t_win *param)
{
	static int	i = 0;
	static int	j = 0;

	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 124)
		mlx_pixel_put((*param).mlx, (*param).win, ++i, j, 0xffea47);
	if (keycode == 125)
		mlx_pixel_put((*param).mlx, (*param).win, i, ++j, 0xffea47);
	if (keycode == 123)
		mlx_pixel_put((*param).mlx, (*param).win, --i, j, 0xffea47);
	if (keycode == 126)
		mlx_pixel_put((*param).mlx, (*param).win, i, --j, 0xffea47);
	if (keycode == 36)
	{
		if (!(*param).press_32)
			(*param).press_32 = 1;
		else 
			(*param).press_32 = 0;
	}
	return (0);
}

static  void  iso ( int  * x ,  int  * y ,  int  z ) 
{ 
	int  previous_x ; 
	int  previous_y ;

	previous_x  =  * x ;
	previous_y  =  * y ; 
	*x  =  ( previous_x  -  previous_y )  *  cos ( 0.523599 ); 
	*y  =  - z  +  ( previous_x  +  previous_y )  *  sin ( 0.523599 ); 
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_win	fdf;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "My new window :)");

	fdf.win = win_ptr;
	fdf.mlx = mlx_ptr;
	fdf.press_32 = 0;

	int	i;
	int	j;
	int	i_n;
	int	j_n;

	/* i = 300;
	while (i < 500)
	{
		j = 150;
		while (j < 350)
		{
			i_n = i;
			j_n = j;
			iso(&i_n, &j_n, 200);
			if (i == 300 || i == 499 || j == 150 || j == 349)
				mlx_pixel_put(mlx_ptr, win_ptr, i_n + 150, j_n + 100, 0xf9b591);
			j++;
		}
		i++;
	}
	i  = 300;
    while (i < 500)
    {
        j = 150;
        while (j < 350)
        {
            i_n = i;
            j_n = j;
            iso(&i_n, &j_n, 230);
			if (i == 300 || i == 499 || j == 150 || j == 349)
            	mlx_pixel_put(mlx_ptr, win_ptr, i_n + 150 , j_n + 100, 0xf9b591);
            j++;
        }
        i++;
    } */


	/* void	*mlx_new_image(void *mlx_ptr,int width,int height);

	int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
		int x, int y); */

	void *image;
	char *data;
	int	size_line;
	int	bpp;
	int	endian;

	//bpp = 1;
	//endian = 1;
	//size_line = 200;

	int width = 200;
	int height = 200;

	image = mlx_new_image(mlx_ptr, 200, 200);
	data = mlx_get_data_addr(image, &bpp, &size_line, &endian);

/* 	i  = 0;
    while (i < 30)
    {
        j = 0;
        while (j < 30)
        {
            *(unsigned int*)(data + i + j) = 0xf9b591;
            j++;
        }
        i++;
    } 
*/

	int k;

	bpp /= 8;
	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 200)
		{
			*(unsigned int*)(data + j * size_line + i * bpp) = 0x027afc;
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(mlx_ptr, win_ptr, image, 50, 50);

	mlx_hook (win_ptr, 17, 0, exit_x, 0);
	mlx_hook (win_ptr, 2, 0, key_press, &fdf);
	mlx_hook (win_ptr, 6, 0, mouse_move, &fdf);

    mlx_loop(mlx_ptr);
}