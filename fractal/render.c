/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:14:00 by yfontene          #+#    #+#             */
/*   Updated: 2024/03/26 16:14:00 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

static void	put_my_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex_num *z, t_complex_num *c, t_fractal *fractal)
{	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

/*
*MANDELBROT
*		z = z^2 + c
*		z initially is (0, 0)
*		c is the actual point
*
*		z = z^2 + c -> z1 = c + c
*
*		JULIA
*		./fractol julia <real> <i> 
*		z = pixel_point + constant
*
*
*	z = z^2 + c
*	z eh o inicio (0,0)
*	c eh o verdadeiro ponto(pixel)
*/
static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex_num	z;
	t_complex_num	c;
	int			i;
	int			color;

	i = 0;
	// pixel coordinate x && y scaled to fit mandel needs 
	//                                 --> 📏 <--			🕹🕹🕹 🕹
	z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;


	mandel_vs_julia(&z, &c, fractal);


	// How many times you want to iterate z^2 + c
	//	to check if the point escaped?
	while (i < fractal->iterations_defintion)
	{
		// actual z^2 + c	
		// z = z^2 + c
		z = sum_complex(square_complex(z), c);
		
		// Is the value escaped???
		// if hypotenuse > 2 i assume the point has escaped
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_defintion);
			put_my_pixel(x, y, &fractal->img, color);
			return ;
		}
		++i;	
	}
	// We are in MANDELBROT given the iterations made
	put_my_pixel(x, y, &fractal->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);	

}
