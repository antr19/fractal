/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:24:59 by fmarsha           #+#    #+#             */
/*   Updated: 2022/06/29 21:52:54 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	vars_init_m(t_vars *vars)
{
	vars->w = 900;
	vars->h = 900;
	vars->scale = 4.7;
	vars->delta_x = vars->w / 2;
	vars->delta_y = vars->h / 2;
	vars->move = 0;
	vars->func = &f_mandelbrot_set;
	vars->c.x = 0;
	vars->c.y = 0;
	vars->bonus = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->w, vars->h, "Fract'ol");
}

void	vars_init_j1(t_vars *vars)
{
	vars->w = 900;
	vars->h = 900;
	vars->scale = 4.7;
	vars->delta_x = vars->w / 2;
	vars->delta_y = vars->h / 2;
	vars->move = 0;
	vars->func = &f_julie_set;
	vars->c.x = 0.1;
	vars->c.y = -0.5;
	vars->bonus = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->w, vars->h, "Fract'ol");
}

void	vars_init_j2(t_vars *vars)
{
	vars->w = 900;
	vars->h = 900;
	vars->scale = 4.7;
	vars->delta_x = vars->w / 2;
	vars->delta_y = vars->h / 2;
	vars->move = 0;
	vars->func = &f_julie_set;
	vars->c.x = -0.98;
	vars->c.y = -0.894;
	vars->bonus = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->w, vars->h, "Fract'ol");
}

void	vars_init_j3(t_vars *vars)
{
	vars->w = 900;
	vars->h = 900;
	vars->scale = 4.7;
	vars->delta_x = vars->w / 2;
	vars->delta_y = vars->h / 2;
	vars->move = 0;
	vars->func = &f_julie_set;
	vars->c.x = -2;
	vars->c.y = -2;
	vars->bonus = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->w, vars->h, "Fract'ol");
}

void	vars_init_s(t_vars *vars)
{
	vars->w = 900;
	vars->h = 900;
	vars->scale = 4.7;
	vars->delta_x = vars->w / 2;
	vars->delta_y = vars->h / 2;
	vars->move = 0;
	vars->func = &f_ship_set;
	vars->c.x = 0.1771;
	vars->c.y = -1.1771;
	vars->bonus = 1;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->w, vars->h, "Fract'ol");
}
