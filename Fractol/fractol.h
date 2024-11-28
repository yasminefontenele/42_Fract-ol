/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:13:03 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/17 17:34:58 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define BLACK               0x000000 
# define WHITE               0xFFFFFF
# define RED                 0xFF0000
# define GREEN               0x00FF00
# define BLUE                0x0000FF
# define MAGENTA_BURST       0xFF00FF
# define NEON_ORANGE         0xFF6600
# define PSYCHEDELIC_PURPLE  0x660066
# define AQUA_DREAM          0x33CCCC
# define ELECTRIC_BLUE       0x0066FF
# define LAVA_RED            0xFF3300

# define ERROR_MESSAGE "Hi! =)\nPlease, for mandelbrot enter:\n\t./fractol \
mandelbrot\nor for Julia: \n\t./fractol julia <value_1> <value_2>\n"

# define WTH 800
# define HGHT 800

typedef struct s_complex_num
{
	double	x;//real part
	double	y;//imaginary part
}				t_cmplx_num;

//Image ID
//valores a partir de mlx_get_data_addr()
typedef struct s_img
{
	void	*img_ptr;//pointer to image struct
	char	*pixel_ptr;//pixel address - pointer to 1 byte
	int		bpp;//bits per pixel
	int		endian; // 0 para big-endian e 1 para little-endian
	int		line_len;//não é utilizado, mas precisa usar
}	t_img;

typedef struct s_fractal
{
	char	*name;
	int		*fractol_name;
	void	*mlx_connection;//para iniciar
	void	*mlx_window;//abrir a janela
	t_img	img;//vem da struct que lida com imagens
	double	escape_value;// hypotenuse
	int		iterations_defintion;//valor ajustado a qualidade da img e render
	int		color;
	double	shift_x;//para controlar as coordenadas
	double	shift_y;
	double	zoom;
	double	julia_x;//parametros proprios
	double	julia_y;//https://pt.wikipedia.org/wiki/Conjunto_de_Julia
}				t_fractal;

int				ft_strncmp(char *s1, char *s2, int i);
void			ft_putstr_fd(char *str, int fd);
double			atoi_float_to_double(char *s);
void			fractal_init(t_fractal *fractal);
double			map(double unscaled_num, double new_min, double new_max,
					double old_max);//interpolacao linear
t_cmplx_num		sum_complex(t_cmplx_num z1, t_cmplx_num z2);
t_cmplx_num		square_complex(t_cmplx_num z);
void			fractal_render(t_fractal *fractal);
int				close_handler(t_fractal *fractal);
//void			ft_zoom(int x, int y, t_fractal *fractal);
//void			ft_dezoom(int x, int y, t_fractal *fractal);
int				key_handler(int keysym, t_fractal *fractal);
//int				mouse_handler(int button, int x, int y, t_fractal *fractal);
int				mouse_handler(int button, int x __attribute__((unused)),
					int y __attribute__((unused)), t_fractal *fractal);
int				julia_track(int x, int y, t_fractal *fractal);
int				fractol_type(char **argv, t_fractal *fractal);

#endif