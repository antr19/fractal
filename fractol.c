/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:42:53 by fmarsha           #+#    #+#             */
/*   Updated: 2022/06/29 21:33:59 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

void	colorised(int x, int y, int f, t_vars *vars)
{
	if (f > vars->max_iter * 0.99 && vars->bonus)
		my_mlx_pixel_put(&(vars->img), x, y, 0x00000000);
	else if (f > vars->max_iter * 0.99)
		my_mlx_pixel_put(&(vars->img), x, y, 0x00FF0000);
	else if (f > vars->max_iter * 0.5 && vars->bonus)
		my_mlx_pixel_put(&(vars->img), x, y, 0x00FF0000);
	else if (f > vars->max_iter * 0.5)
		my_mlx_pixel_put(&(vars->img), x, y, 0x00FC6f03);
	else if (f > vars->max_iter * 0.35)
		my_mlx_pixel_put(&(vars->img), x, y, 0x00FCBA03);
	else if (f > vars->max_iter * 0.2)
		my_mlx_pixel_put(&(vars->img), x, y, 0x00FCF803);
	else if (f > 0)
		my_mlx_pixel_put(&(vars->img), x, y, 0x00C6FC03);
	else
		my_mlx_pixel_put(&(vars->img), x, y, 0x005EFC03);
}

void	fractal_creater(t_vars *vars)
{
	int			f;
	int			x;
	int			y;
	t_complex	z;

	mlx_clear_window(vars->mlx, vars->win);
	vars->img.img = mlx_new_image(vars->mlx, vars->w, vars->h);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
	&(vars->img).bits_per_pixel, &(vars->img).line_length, &(vars->img).endian);
	x = -1;
	while (++x < vars->w)
	{
		y = -1;
		while (++y < vars->h)
		{
			z.x = (x - vars->delta_x) * vars->scale / vars->w;
			z.y = (y - vars->delta_y) * vars->scale / vars->h;
			vars->max_iter = 50 / vars->scale;
			if (vars->max_iter > 120)
				vars->max_iter = 120;
			f = (*vars->func)(z, vars->c, vars->max_iter);
			colorised(x, y, f, vars);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2 && get_fractal(av[1], &vars))
	{
		fractal_creater(&vars);
		hooks(&vars);
		mlx_loop(vars.mlx);
	}
	else
		ft_putstr_fd("usage: mandelbrot julia1 julia2 julia3 ship", 1);
	return (1);
}
