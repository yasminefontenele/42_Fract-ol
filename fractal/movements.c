/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:08:18 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/11 08:46:39 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//esta na documentao, aba "eventos"
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
					fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
						fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);	
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);	
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);	
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);	
	else if (keysym == XK_plus)
		fractal->iterations_defintion += 10;
	else if (keysym == XK_minus)	
		fractal->iterations_defintion -= 10;

	// refresh the image
	fractal_render(fractal);
	return 0;
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	//Zoom in
	if (button == Button5)
	{
		fractal->zoom *= 0.95;
	}
	//Zoom out
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	// refresh
	fractal_render(fractal);
	return 0;
}

//serve para dinamizar a "Julia"
int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return 0;
}