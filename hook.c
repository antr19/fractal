/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:42:22 by fmarsha           #+#    #+#             */
/*   Updated: 2022/06/29 21:44:49 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mlx_keycode.h"
#include "fractol.h"
#include <stdlib.h>

int	fractol_exit(t_vars *vars)
{
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx && vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		fractol_exit(vars);
	if (keycode == UP_KEY)
		vars->delta_y -= 10;
	if (keycode == DOWN_KEY)
		vars->delta_y += 10;
	if (keycode == RIGHT_KEY)
		vars->delta_x += 10;
	if (keycode == LEFT_KEY)
		vars->delta_x -= 10;
	fractal_creater(vars);
	return (0);
}

int	scroll_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == SCROLLDOWN_KEY)
	{
		vars->scale *= 1.1;
		vars->delta_x += (vars->w / 2 - x) / (2 * vars->scale);
		vars->delta_y += (vars->h / 2 - y) / (2 * vars->scale);
	}
	else if (keycode == SCROLLUP_KEY)
	{
		vars->scale *= 0.9;
		vars->delta_x += (vars->w / 2 - x) / (2 * vars->scale);
		vars->delta_y += (vars->h / 2 - y) / (2 * vars->scale);
	}
	fractal_creater(vars);
	return (0);
}

void	hooks(t_vars *vars)
{
	mlx_hook(vars->win, KEYPRESS, 0, key_hook, vars);
	mlx_hook(vars->win, BUTTONPRESS, 0, scroll_hook, vars);
	mlx_hook(vars->win, DESTROYNOTIFY, 0, fractol_exit, vars);
}
