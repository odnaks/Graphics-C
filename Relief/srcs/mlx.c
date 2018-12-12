#include <stdlib.h>
//#include <mlx_int.h>
#include "mlx.h"
#include "fdf.h"
#include <stdio.h>

int close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int mlx()
{
	void *mlx_ptr;
	void *win_ptr;
	void *params[2];

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 200, 200, 0xFFFFFF);
	params[0] = mlx_ptr;
	params[1] = win_ptr;
	mlx_hook(win_ptr,2, 0, key_hook, params);
	mlx_hook(win_ptr, 17, 0, close, params);
	mlx_loop(mlx_ptr);
	printf("esc");
	free(win_ptr);
	free(mlx_ptr);
	return (0);
}
