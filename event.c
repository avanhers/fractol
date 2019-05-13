/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 10:47:10 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 18:32:39 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractal.h"
#include <time.h>
#include <stdlib.h>

int		event(t_env *env)
{
	srand(time(NULL));
	env->lock = 0;
	mlx_hook(env->win, 4, 0, &mouse_press, env);
	mlx_hook(env->win, 2, 0, &key_press, env);
	mlx_hook(env->win, 6, 0, &mouse_move, env);
	mlx_hook(env->win, 3, 0, &key_release, env);
	mlx_hook(env->win, 5, 0, &mouse_release, env);
	mlx_loop(env->mlx_ptr);
	return (1);
}
