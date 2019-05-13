/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:34:41 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/09 19:06:06 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthread.h"
#include "mlx.h"
#include "fractal.h"

int		launch(t_env *env)
{
	t_args	args[THREADS];
	int		i;

	i = -1;
	while (++i < THREADS)
	{
		args[i].env = env;
		args[i].nt = i;
		pthread_create(&args[i].t, NULL, draw, &args[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(args[i].t, NULL);
	mlx_put_image_to_window(env->mlx_ptr, env->win, env->img.img_ptr, 0, 0);
	return (1);
}
