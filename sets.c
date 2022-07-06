/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:51:50 by fmarsha           #+#    #+#             */
/*   Updated: 2022/06/29 21:37:30 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	f_mandelbrot_set(t_complex z, t_complex c, int max_i)
{
	double		xtemp;
	int			i;

	i = -1;
	c = z;
	while (pow(z.x, 2.0) + pow(z.y, 2.0) < 4 && ++i < max_i)
	{
		xtemp = pow(z.x, 2.0) - pow(z.y, 2.0);
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = xtemp + c.x;
	}
	return (i);
}

int	f_julie_set(t_complex z, t_complex c, int max_i)
{
	double		xtemp;
	int			i;

	i = -1;
	while (pow(z.x, 2.0) + pow(z.y, 2.0) < 4 && ++i < max_i)
	{
		xtemp = pow(z.x, 2.0) - pow(z.y, 2.0);
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = xtemp + c.x;
	}
	return (i);
}

int	f_ship_set(t_complex z, t_complex c, int max_i)
{
	double		xtemp;
	int			i;

	i = -1;
	while (pow(z.x, 2.0) + pow(z.y, 2.0) < 4 && ++i < max_i)
	{
		xtemp = pow(z.x, 2.0) - pow(z.y, 2.0);
		z.y = 2.0 * fabs(z.x) * fabs(z.y) + c.y;
		z.x = xtemp + c.x;
	}
	return (i);
}
