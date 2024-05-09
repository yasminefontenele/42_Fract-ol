/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:17:24 by yfontene          #+#    #+#             */
/*   Updated: 2024/03/26 15:17:24 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

int main(int ac, char **av)
{
	t_fractal	fractal;

	if(ac == 2 &&!ft_strncmp(av[1], "mandelbrot", 10) || ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		if(!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atoi_float_to_double(av[2]);
			fractal.julia_y = atoi_float_to_double(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
