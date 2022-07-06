/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:32:30 by fmarsha           #+#    #+#             */
/*   Updated: 2022/06/29 21:57:02 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fractol.h"
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	if (i != j)
		return (1);
	while (*s1 == *s2 && s1 && s2 && *s1 && *s2 && i--)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	get_fractal(char *s, t_vars *vars)
{
	if (!ft_strcmp(s, "mandelbrot"))
		vars_init_m(vars);
	else if (!ft_strcmp(s, "julia1"))
		vars_init_j1(vars);
	else if (!ft_strcmp(s, "julia2"))
		vars_init_j2(vars);
	else if (!ft_strcmp(s, "julia3"))
		vars_init_j3(vars);
	else if (!ft_strcmp(s, "ship"))
		vars_init_s(vars);
	else
		return (0);
	return (1);
}
