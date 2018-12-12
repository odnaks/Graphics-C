put_pixel_to_image(int x, int y, int color)
{
    *(unsigned int*)(data + j * size_line + i * bpp) = color;
}


void		draw_line(void *mlx_ptr, void *win_ptr, s_point3d pt_a, s_point3d pt_b)
{
            int dx = (x1 > x0) ? (x1 - x0) : (x0 - x1);
            int dy = (y1 > y0) ? (y1 - y0) : (y0 - y1);

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



image = mlx_new_image(mlx_ptr, 200, 200);
data = mlx_get_data_addr(image, &bpp, &size_line, &endian);

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


/* char *mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );

mlx_get_data_addr () returns information about the created image, allowing a user to modify it later. The
img_ptr parameter specifies the image to use. The three next parameters should be the addresses of three
different valid integers. bits_per_pixel will be filled with the number of bits needed to represent a pixel
color (also called the depth of the image). size_line is the number of bytes used to store one line of the
image in memory. This information is needed to move from one line to another in the image. endian tells
you wether the pixel color in the image needs to be stored in little endian ( endian == 0), or big endian (
endian == 1).
mlx_get_data_addr returns a char * address that represents the begining of the memory area where the
image is stored. From this adress, the first bits_per_pixel bits represent the color of the first pixel in the first
line of the image. The second group of bits_per_pixel bits represent the second pixel of the first line, and so
on. Add size_line to the adress to get the begining of the second line. You can reach any pixels of the
image that way */