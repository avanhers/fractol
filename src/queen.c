/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:08:40 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/09 15:27:13 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			escape_time_q(t_pixel pixel, t_env *env)
{
	double	z[2];
	double	z2[2];
	int		i;
	double	c[2];

	i = 0;
	c[R] = pixel.x * env->dx + env->x_min;
	c[I] = -(pixel.y * env->dy + env->y_min);
	z[R] = 0;
	z[I] = 0;
	z2[R] = z[R] * z[R];
	z2[I] = z[I] * z[I];
	while (z2[R] + z2[I] < 4 && ++i < env->max_iter)
	{
		if (z[I] < 0)
			z[I] = -z[I];
		z[I] = (3 * z2[R] - z2[I]) * z[I] + c[I];
		z[R] = (z2[R] - (z2[I] * 3)) * z[R] + c[R];
		z2[R] = z[R] * z[R];
		z2[I] = z[I] * z[I];
	}
	return (i);
}

void		queen(t_pixel pixel, void *envi)
{
	int				i;
	static t_env	*env = NULL;

	if (!env)
		env = (t_env*)envi;
	i = escape_time_q(pixel, env);
	draw_pixel(pixel, env, i);
}
