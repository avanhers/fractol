/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:19:54 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 14:04:07 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_pixel(t_pixel pixel, t_env *env, int value)
{
	if (value == env->max_iter)
		env->img.data[pixel.y * WIN_WIDTH + pixel.x] = 0;
	if (value < env->max_iter)
		env->img.data[pixel.y * WIN_WIDTH + pixel.x] = env->color[value].number;
}

double	convert(int old, double min, double max, int lenght)
{
	double new;

	new = old * (max - min) / lenght + min;
	return (new);
}

void	*draw(void *arg)
{
	t_pixel pixel;

	pixel.y = -1;
	((t_args*)arg)->env->dx = (((t_args*)arg)->env->x_max
		- ((t_args*)arg)->env->x_min) / WIN_WIDTH;
	((t_args*)arg)->env->dy = (((t_args*)arg)->env->x_max
		- ((t_args*)arg)->env->x_min) / WIN_HEIGHT;
	while (++pixel.y < WIN_HEIGHT)
	{
		pixel.x = ((t_args*)arg)->nt;
		while (pixel.x < WIN_WIDTH)
		{
			((t_args*)arg)->env->fract_fu(pixel, ((t_args*)arg)->env);
			pixel.x += THREADS;
		}
	}
	pthread_exit(NULL);
}
