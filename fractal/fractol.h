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
//gcc *.c -Lminilibx-linux -lmlx_Linux -lx11 -lXext -o fractol
//-lx11 -lXext vem da documentacao
#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

// colors //
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)
#define LIME_SHOCK      "\x1b[38;2;204;255;0m"
#define HOT_PINK        "\x1b[38;2;255;102;178m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
//#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
//#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

#define ERROR_MESSAGE "Hi! =)\nPlease, for" LIME_SHOCK " mandelbrot" ANSI_COLOR_RESET " enter: \n\t./fractol mandelbrot\ \nor for" HOT_PINK " Julia:" ANSI_COLOR_RESET "\n\t./fractol julia <value_1> <value_2>\n"

#define WIDTH	800
#define	HEIGHT	800

//Complex numbers
typedef struct s_complex_num
{
	double x;//real part
	double y;//imaginary part
} t_complex_num;

//Image ID
//valores a partir de mlx_get_data_addr()
typedef struct s_img
{
	void *img_ptr;//pointer to image struct
	char *pixel_ptr;//pixel address - pointer to 1 byte
	int bpp;//bits per pixel
	int line_len;
	int endian; // 0 para big-endian e 1 para little-endian
}	t_img;

//Fractals ID
typedef struct s_fractals
{
	char *name;
	void *mlx_connection;// mlx_init()
	void *mlx_window;//mlx_new_window
	t_img *img;//vem sa struct que lida com imagens
	double scape_value;//hipotenusa
	int	iterations_definition;
	double zoom;
	double shift_x;
	double shift_y;
	double julia_x;
	double julia_y;
}	t_fractal;

//str_utils.c
int		ft_strncmp(char *s1, char *s2, int i);
void	ft_putstr_fd(char *str, int fd);
double	atoi_float_to_double(char *s);

//init.c
void	data_init(t_fractal *fractal);
void	fractal_init(t_fractal *fractal);

//math
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);//interpolacao linear
t_complex_num	sum_complex(t_complex_num z1, t_complex_num z2);
t_complex_num square_complex(t_complex_num z);


//render
void fractal_render(t_fractal *fractal);

#endif