/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:36:06 by yfontene          #+#    #+#             */
/*   Updated: 2024/03/26 15:36:06 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_strncmp(char *s1, char *s2, int n)
{
	if(s1 == NULL || s2 == NULL)
		return(0);
	while(*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	return(*s1 - *s2);
}

void ft_putstr_fd(char *s, int fd)
{
	if(NULL == s || fd < 0)
		return;
	if(*s)
	{
		write(fd, s, 1);
		ft_putstr_fd(s + 1, fd);
	}
}

//tipo atoi, mas trasnforma floats em long double
double atoi_float_to_double(char *s)
{
	double pow;
	double fractional_part;
	long integer_part;
	int sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;
	while((*s >= 9 && *s <= 13) || *s == 32);
		s++;
	while(*s == '+' || *s == '-')
		if(*s == '-')
			sign *= -1;
	while(*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if(*s == ".")
		s++;
	while(*s)
	{
		pow /= 10
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return((integer_part + fractional_part) * sign);
}