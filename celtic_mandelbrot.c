/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:54:11 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 14:04:03 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			escape_time_c(t_pixel pixel, t_env *env)
{
	double	z[2];
	double	z2[2];
	int		i;
	double	c[2];
	double	tmp;

	i = 0;
	z[R] = 0;
	z[I] = 0;
	z2[I] = 0;
	z2[R] = 0;
	c[R] = pixel.x * env->dx + env->x_min;
	c[I] = pixel.y * env->dy + env->y_min;
	while (z2[R] + z2[I] < 4 && ++i < env->max_iter)
	{
		if ((tmp = z[R] * z[R] - z[I] * z[I]) < 0)
			tmp = -tmp;
		z[I] = (z[R] + z[I]) * (z[R] + z[I]) - z2[R] - z2[I] + c[I];
		z[R] = tmp + c[R];
		z2[R] = z[R] * z[R];
		z2[I] = z[I] * z[I];
	}
	return (i);
}

void		celtic_mandelbrot(t_pixel pixel, void *envi)
{
	int				i;
	static t_env	*env = NULL;

	if (!env)
		env = (t_env*)envi;
	i = escape_time_c(pixel, env);
	draw_pixel(pixel, env, i);
}
