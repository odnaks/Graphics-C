#include "mlx.h"

//exit
#include "stdlib.h"

int	key_button(int button, void *param)
{
	if (button == 53)
		exit(1);
	return (0);
}

int	exit_x()
{
	exit(1);
}

int	main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xffffff);

	mlx_hook(win_ptr, 2, 0 , key_button, 0);
	mlx_loop(mlx_ptr);
}
