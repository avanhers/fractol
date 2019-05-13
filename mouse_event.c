/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:56:46 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 18:36:52 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx.h"

void	zoom(int x, int y, double zoom, t_env *env)
{
	double	tmp;
	double	xu;
	double	yu;

	xu = convert(x, env->x_min, env->x_max, WIN_WIDTH);
	tmp = (env->x_min - xu) / zoom + xu;
	env->x_max = tmp + (env->x_max - env->x_min) / zoom;
	env->x_min = tmp;
	yu = convert(y, env->y_min, env->y_max, WIN_HEIGHT);
	tmp = (env->y_min - yu) / zoom + yu;
	env->y_max = tmp + (env->y_max - env->y_min) / zoom;
	env->y_min = tmp;
	launch(env);
}

int		mouse_press(int button, int x, int y, t_env *env)
{
	if (button == 5 && destroy_create_image(env))
	{
		zoom(x, y, 1.2, env);
		return (1);
	}
	if (button == 4 && destroy_create_image(env))
	{
		zoom(x, y, 0.8, env);
		return (1);
	}
	return (0);
}

int		mouse_release(int button, int x, int y, t_env *env)
{
	x = 0;
	y = 0;
	if (button == 1)
		env->lock = 1;
	if (button == 2)
		env->lock = 0;
	if (button == 3)
		env->autozoom = 1 - env->autozoom;
	return (1);
}

int		mouse_move(int x, int y, t_env *env)
{
	if (env->name == 'j' && env->lock == 0)
	{
		destroy_create_image(env);
		env->c[R] = 2 * (double)x / WIN_WIDTH - 1;
		env->c[I] = 2 * (double)y / WIN_HEIGHT - 1;
		launch(env);
	}
	if (env->autozoom == 1 && destroy_create_image(env))
	{
		zoom(x, y, 1.1, env);
	}
	return (1);
}
