/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:13:03 by yfontene          #+#    #+#             */
/*   Updated: 2024/03/26 15:13:03 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

#define WIDTH	800
#define	HEIGHT	800


// colors //
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

//Complex numbers

typedef struct s_complex
{
	double x;//real part
	double y;//imaginary part
} t_complex;

//Image ID
typedef struct s_img
{
	void *img_ptr;
	char *pixel_ptr; //pixel address
	int bpp; //bits per pixel
	int line_len;
	int endian; // 0 para big-endian e 1 para little-endian
} t_img;

//Fractals ID
typedef struct s_fractals
{
	char *name;
	void *mlx_connection;
	void *mlx_window;
	t_img *img;
	double zoom;
	double shift_x;
	double shift_y;
	double julia_x;
	double julia_y;
} t_fractals;

//str_utils.c
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);
double	atoi_float_to_double(char *s);

//init.c
void	fractal_init(t_fractal *fractal);

#endif