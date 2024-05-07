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

static void put_my_pixel(int x, int y, t_img *img, int color)
{
	int offset;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	(unsigned int *)(img->pixel_ptr + offset) = color;
}
/*
*	z = z^2 + c
*	z eh o inicio (0,0)
*	c eh o verdadeiro ponto(pixel)
*/

static void handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex_num	z;
	t_complex_num	c;
	int	i;
	int color;
	i = 0;
	//primeira interacao
	z.x = 0.0;
	z.y = 0.0;
	//para caber no mandelbrot
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HEIGHT);

	while(i < fractal->iterations_definition)
	{
		z= sum_complex(square_complex(z), c);
		if((z.x *z.x) + (z.y * z.y) > fractal->scape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_definition);
			put_my_pixel(x, y, fractal->img, color);
			return;
		}
		++i;
	}
	//we are in mandalbrot
	put_my_pixel(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}

void fractal_render(t_fractal *fractal)
{
	int x;
	int y;

	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while(++x < WIDTH)
		{
			Handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}