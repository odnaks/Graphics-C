#include <mlx.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>


int exit_x(void)
{
    exit(1);
}

void		ft_putchar(char c)
{
	write (1, &c, 1);
}

int	key_press(int keycode, void *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

void		Bresenham(void *mlx_ptr, void *win_ptr,
							int x0, int y0, int x1, int y1)
{
            //Изменения координат
            int dx = (x1 > x0) ? (x1 - x0) : (x0 - x1);
            int dy = (y1 > y0) ? (y1 - y0) : (y0 - y1);
            //Направление приращения
            int sx = (x1 >= x0) ? (1) : (-1);
            int sy = (y1 >= y0) ? (1) : (-1);
 
            if (dy < dx)
            {
                int d = (dy << 1) - dx;
                int d1 = dy << 1;
                int d2 = (dy - dx) << 1;
                mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xffffff);
                int x = x0 + sx;
                int y = y0;
                for (int i = 1; i <= dx; i++)
                {
                    if (d > 0)
                    {
                        d += d2;
                        y += sy;
                    }
                    else
                        d += d1;
					mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
					x+=sx;
                }
            }
            else
            {
                int d = (dx << 1) - dy;
                int d1 = dx << 1;
                int d2 = (dx - dy) << 1;
				mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xffffff);
                int x = x0;
                int y = y0 + sy;
                for (int i = 1; i <= dy; i++)
                {
                    if (d > 0)
                    {
                        d += d2;
                        x += sx;
                    }
                    else
                        d += d1;
                    mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
                    y+=sy;
                }
            }
        }
/* int		deal_key(int key, void *param)
{
	ft_putchar ('X');
//	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xf92391);
	return (0);
}
 */
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

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 700, "My new window :)");

	int	i;
	int	j;

	int matrix[11][19] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0,
	0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0,
	0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0,
	0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0,
	0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

	int x0;
	int y0;
	int x1;
	int y1;

	i = 0;
	while (i < 19)
	{
		j = 0;
		while (j < 11)
		{
		
			if (j != 0)
				{
					x0 = 30 * i + 400;
					y0 = 30 * j;

					x1 = 30 * i + 400;
					y1 = 30 * (j - 1);
					iso(&x0, &y0, 2 * matrix[j][i]);
					iso(&x1, &y1, 2 * matrix[j - 1][i]);
					Bresenham (mlx_ptr, win_ptr, x0, y0, x1, y1);
				}
			if (i != 0)
				{
					x0 = 30 * i + 400;
					y0 = 30 * j;

					x1 = 30 * (i - 1) + 400;
					y1 = 30 * j;
					iso(&x0, &y0, 2 * matrix[j][i]);
					iso(&x1, &y1, 2 * matrix[j][i - 1]);
					Bresenham (mlx_ptr, win_ptr, x0, y0, x1, y1);
				}
			j++;
		}
		i++;
	}

	mlx_hook(win_ptr, 17, 0, exit_x, 0);
	mlx_hook (win_ptr, 2, 0, key_press, 0);

	mlx_loop(mlx_ptr);
}