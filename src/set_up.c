/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:29:41 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 14:04:11 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	setup_julia(void *envi)
{
	t_env *env;

	env = (t_env*)envi;
	set_color_mine(env);
	env->name = 'j';
	env->x_min = -1.25;
	env->x_max = 1.25;
	env->y_min = -1.25;
	env->y_max = 1.25;
	env->c[R] = 0;
	env->c[I] = 0;
	env->max_iter = 50;
	env->lock = 0;
}

void	setup_mandelbrot(void *envi)
{
	t_env *env;

	env = (t_env*)envi;
	set_color_mine(env);
	env->name = 'm';
	env->x_min = -2;
	env->x_max = 0.5;
	env->y_min = -1.25;
	env->y_max = 1.25;
	env->max_iter = 50;
}

void	setup_burning_ship(void *envi)
{
	t_env *env;

	env = (t_env*)envi;
	set_color_mine(env);
	env->name = 'b';
	env->x_min = -2;
	env->x_max = 1.5;
	env->y_min = -2;
	env->y_max = 1.5;
	env->max_iter = 50;
}

void	setup_celtic_mandelbrot(void *envi)
{
	t_env *env;

	env = (t_env*)envi;
	set_color_mine(env);
	env->name = 'c';
	env->x_min = -2;
	env->x_max = 2;
	env->y_min = -2;
	env->y_max = 2;
	env->max_iter = 50;
}

void	setup_phoenix(void *envi)
{
	t_env *env;

	env = (t_env*)envi;
	set_color_mine(env);
	env->name = 'p';
	env->x_min = -1.25;
	env->x_max = 1.25;
	env->y_min = -1.25;
	env->y_max = 1.25;
	env->c[R] = 0.56667;
	env->c[I] = -0.5;
	env->max_iter = 50;
}
