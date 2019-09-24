/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:22:10 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/09 15:24:39 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			escape_time_t(t_pixel pixel, t_env *env)
{
	double	z[2];
	double	z2[2];
	int		i;
	double	c[2];

	i = 0;
	c[R] = pixel.x * env->dx + env->x_min;
	c[I] = pixel.y * env->dy + env->y_min;
	z[R] = 0;
	z[I] = 0;
	z2[R] = z[R] * z[R];
	z2[I] = z[I] * z[I];
	while (z2[R] + z2[I] < 4 && ++i < env->max_iter)
	{
		z[I] = -2 * z[R] * z[I] + c[I];
		z[R] = z2[R] - z2[I] + c[R];
		z2[R] = z[R] * z[R];
		z2[I] = z[I] * z[I];
	}
	return (i);
}

void		tricorn(t_pixel pixel, void *envi)
{
	int				i;
	static t_env	*env = NULL;

	if (!env)
		env = (t_env*)envi;
	i = escape_time_t(pixel, env);
	draw_pixel(pixel, env, i);
}
