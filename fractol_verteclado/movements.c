/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:08:18 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/16 18:45:06 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*padrão da biblioteca:
* int (*f)(void *param)
*serve para fechar a janela
*/
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

/*
* int (*f)(int keycode, void *param)
*/
int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler (fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_KP_Add)
		fractal->zoom *= 1.1;
	else if (keysym == XK_KP_Subtract)
		fractal->zoom /= 1.1;
	else if (keysym == XK_a)
		fractal->color = 0x00ff00;
	else if (keysym == XK_b)
		fractal->color = 0xff69b4;
	else if (keysym == XK_c)
		fractal->color = 0xffdab9;
	fractal_render (fractal);
	return (0);
}

/*void ft_zoom(int x, int y, t_fractal *fractal)
{
    fractal->minreal = (x / fractal->zoom + fractal->minreal) - (x / (fractal->zoom * 1.2));
    fractal->min_i = (y / fractal->zoom + fractal->min_i) - (y / (fractal->zoom * 1.2));
    fractal->zoom *= 1.2;
    fractal->max_n++;
}

void ft_dezoom(int x, int y, t_fractal *fractal)
{
    fractal->minreal = (x / fractal->zoom + fractal->minreal) - (x / (fractal->zoom / 1.2));
    fractal->min_i = (y / fractal->zoom + fractal->min_i) - (y / (fractal->zoom / 1.2));
    fractal->zoom /= 1.2;
    fractal->max_n--;
}
*int (*f)(int button, int x, int y, void *param)
int		mouse_handler(int mousecode, int x, int y, t_fractal *fractal)
{
	if (mousecode == 5 || mousecode == 2)
		ft_zoom(x, y, fractal);
	else if (mousecode == 4 || mousecode == 1)
		ft_dezoom(x, y, fractal);
	mlx_clear_window(fractal->mlx_connection, fractal->mlx_connection);
		fractal_render(fractal);
	return (0);
}*/

int	mouse_handler(int button, t_fractal *fractal)
{
	if (button == Button5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}

/*
* Para seguir o mouse e modificar Julia
* int (*f)(int x, int y, void *param)
*/
int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, WTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, HGHT) * fractal->zoom)
			+ fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
