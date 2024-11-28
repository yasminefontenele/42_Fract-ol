/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:07:08 by yfontene          #+#    #+#             */
/*   Updated: 2024/05/11 10:37:16 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Fazer o reescalamento do tamanho para as coordenadas [0..799] -> [-2..+2]
double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}

t_cmplx_num	sum_complex(t_cmplx_num z1, t_cmplx_num z2)
{
	t_cmplx_num	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/*
* Parte real (x) real = (x^2 - y^2)
* Parte imaginaria (y) i =  2*x*y
*/
t_cmplx_num	square_complex(t_cmplx_num z)
{
	t_cmplx_num	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
