#include <mlx_int.h>
#include "fdf.h"
#include "mlx.h"
#include <stdio.h>



int expose_hook(void *param)
{

}

int key_hook(int keycode, void *params)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = ((void **)params)[0];
	win_ptr = ((void **)params)[1];

	if (keycode == 53) //esc
	{
		printf("%d\n", keycode);
		((mlx_ptr_t *)mlx_ptr)->main_loop_active = 0;
		mlx_clear_window(mlx_ptr, win_ptr);
		mlx_destroy_window(mlx_ptr,win_ptr);
	}
	if (keycode != 53)
	{
		printf("%d\n", keycode);
	}
}

int mouse_hook(int button,int x,int y,void *param)
{
	return (0);
}
