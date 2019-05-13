/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:53:47 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 13:58:01 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	move(int keycode, t_env *env)
{
	double dx;
	double dy;

	dx = (env->x_max - env->x_min) / WIN_WIDTH;
	dy = (env->y_max - env->y_min) / WIN_HEIGHT;
	if (keycode == 123)
	{
		env->x_min += 2 * dx;
		env->x_max += 2 * dx;
	}
	if (keycode == 124)
	{
		env->x_min -= 2 * dx;
		env->x_max -= 2 * dx;
	}
	if (keycode == 125)
	{
		env->y_min -= 2 * dy;
		env->y_max -= 2 * dy;
	}
	if (keycode == 126)
	{
		env->y_min += 2 * dy;
		env->y_max += 2 * dy;
	}
}

int		key_release(int keycode, t_env *env)
{
	if (keycode == 83 && destroy_create_image(env))
		set_color_black(env);
	if (keycode == 84 && destroy_create_image(env))
		set_color_mine(env);
	if (keycode == 85 && destroy_create_image(env))
		set_color_random(env);
	if (keycode == 86 && destroy_create_image(env))
		set_color_random2(env);
	launch(env);
	if (keycode == 53)
		close_all(env);
	return (0);
}

int		key_press(int keycode, t_env *env)
{
	if (keycode >= 123 && keycode <= 126)
	{
		destroy_create_image(env);
		move(keycode, env);
		launch(env);
	}
	if (keycode == 69 && env->max_iter < MAX_ITER - 2)
	{
		destroy_create_image(env);
		env->max_iter += 2;
		launch(env);
	}
	if (keycode == 78 && env->max_iter > 2)
	{
		destroy_create_image(env);
		env->max_iter -= 2;
		launch(env);
	}
	return (1);
}
