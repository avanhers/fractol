/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:08:30 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/09 15:41:06 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		escape_time_j(t_pixel pixel, t_env *env)
{
	double	z[2];
	double	z2[2];
	int		i;

	i = 0;
	z[R] = pixel.x * env->dx + env->x_min;
	z[I] = pixel.y * env->dy + env->y_min;
	z2[R] = z[R] * z[R];
	z2[I] = z[I] * z[I];
	while (z2[R] + z2[I] < 4 && ++i < env->max_iter)
	{
		z[I] = (z[R] + z[I]) * (z[R] + z[I]) - z2[R] - z2[I] + env->c[I];
		z[R] = z2[R] - z2[I] + env->c[R];
		z2[R] = z[R] * z[R];
		z2[I] = z[I] * z[I];
	}
	return (i);
}

void	julia(t_pixel pixel, void *envi)
{
	t_env	*env;
	int		i;

	env = (t_env*)envi;
	i = escape_time_j(pixel, env);
	draw_pixel(pixel, env, i);
}
