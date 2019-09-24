/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:50:08 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 14:04:06 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			escape_time_cr(t_pixel pixel, t_env *env)
{
	double	z[2];
	double	z2[2];
	int		i;
	double	c[2];

	i = 0;
	z[R] = 0;
	z[I] = 0;
	z2[I] = 0;
	z2[R] = 0;
	c[R] = pixel.x * env->dx + env->x_min;
	c[I] = pixel.y * env->dy + env->y_min;
	while (z2[R] + z2[I] < 4 && ++i < env->max_iter)
	{
		z[I] = (z2[R] * 3 - z2[I]) * z[I] + c[I];
		z[R] = -(z2[R] - (z2[I] * 3)) * z[R] + c[R];
		z2[R] = z[R] * z[R];
		z2[I] = z[I] * z[I];
	}
	return (i);
}

void		cross(t_pixel pixel, void *envi)
{
	int				i;
	static t_env	*env = NULL;

	if (!env)
		env = (t_env*)envi;
	i = escape_time_cr(pixel, env);
	draw_pixel(pixel, env, i);
}
