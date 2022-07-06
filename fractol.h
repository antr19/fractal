/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:22:32 by fmarsha           #+#    #+#             */
/*   Updated: 2022/06/29 21:59:00 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_complex{
	double	x;
	double	y;
}				t_complex;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			max_iter;
	int			w;
	int			h;
	int			delta_x;
	int			delta_y;
	double		scale;
	int			move;
	t_data		img;
	int			(*func)(t_complex z, t_complex c, int max_i);
	int			bonus;
	t_complex	c;
}				t_vars;

void	hooks(t_vars *vars);
void	fractal_creater(t_vars *vars);
int		f_mandelbrot_set(t_complex z, t_complex c, int max_i);
int		f_julie_set(t_complex z, t_complex c, int max_i);
int		f_ship_set(t_complex z, t_complex c, int max_i);
void	vars_init_m(t_vars *vars);
void	vars_init_j1(t_vars *vars);
void	vars_init_j2(t_vars *vars);
void	vars_init_j3(t_vars *vars);
void	vars_init_s(t_vars *vars);
int		get_fractal(char *s, t_vars *vars);

#endif
