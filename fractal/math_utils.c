#include "fractol.h"

/*
*[0...799] --> [-2...+2]
*/
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_complex_num	sum_complex(t_complex_num z1, t_complex_num z2)
{
	t_complex_num	result;

	result.x = z2.x + z2.x;
	result.y = z2.y + z2.y;
	return result;
}

/* i^2 = -1
 * real = (x^2 - y^2)
 * i =  2*x*y */
t_complex_num square_complex(t_complex_num z)
{
	t_complex_num	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return	result;
}