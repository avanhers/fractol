/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:02:46 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 14:04:10 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			escape_time_p(t_pixel pixel, t_env *env)
{
	double	z[2];
	double	z2[2];
	double	z3[3];
	int		i;

	i = 0;
	z[R] = 0;
	z[I] = 0;
	z2[I] = pixel.x * env->dx + env->x_min;
	z2[R] = -(pixel.y * env->dy + env->y_min);
	z3[R] = 2 * z2[R] * z2[I] + env->c[I] * z[I];
	z3[I] = z2[R] * z2[R] - z2[I] * z2[I] + env->c[I] * z[R] + env->c[R];
	while (z3[R] * z3[R] + z3[I] * z3[I] < 25 && ++i < env->max_iter)
	{
		z3[I] = 2 * z2[R] * z2[I] + env->c[I] * z[I];
		z3[R] = z2[R] * z2[R] - z2[I] * z2[I] + env->c[I] * z[R] + env->c[R];
		z[R] = z2[R];
		z[I] = z2[I];
		z2[R] = z3[R];
		z2[I] = z3[I];
	}
	return (i);
}

void		phoenix(t_pixel pixel, void *envi)
{
	t_env	*env;
	int		i;

	env = (t_env*)envi;
	i = escape_time_p(pixel, env);
	draw_pixel(pixel, env, i);
}
