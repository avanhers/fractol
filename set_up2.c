/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:12:57 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 14:04:12 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	setup_tricorn(void *envi)
{
	t_env	*env;

	env = (t_env*)envi;
	set_color_mine(env);
	env->name = 't';
	env->x_min = -2.5;
	env->x_max = 2.5;
	env->y_min = -2.5;
	env->y_max = 2.5;
	env->max_iter = 50;
}

void	setup_queen(void *envi)
{
	t_env	*env;

	env = (t_env*)envi;
	set_color_mine(env);
	env->name = 'q';
	env->x_min = -1.5;
	env->x_max = 1.5;
	env->y_min = -1.5;
	env->y_max = 1.5;
	env->max_iter = 50;
}

void	setup_cross(void *envi)
{
	t_env *env;

	env = (t_env*)envi;
	set_color_mine(env);
	env->name = 'r';
	env->x_min = -1.5;
	env->x_max = 1.5;
	env->y_min = -1.5;
	env->y_max = 1.5;
	env->max_iter = 50;
}
