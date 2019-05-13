/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:29:50 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 12:09:22 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractal.h"
#include "stdlib.h"

void	set_color_black(t_env *env)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		env->color[i].channel[0] = sin(i * 0.08) * 150;
		env->color[i].channel[1] = sin(i * 0.08) * 150;
		env->color[i].channel[2] = sin(i * 0.08) * 150;
		i++;
	}
}

void	set_color_mine(t_env *env)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		env->color[i].channel[0] = sin(i * 0.15 + 4) * 100 + 127;
		env->color[i].channel[1] = sin(i * 0.15 + 2) * 100 + 127;
		env->color[i].channel[2] = sin(i * 0.15 + 1) * 100 + 127;
		i++;
	}
}

void	set_color_random(t_env *env)
{
	int	i;
	int	k;
	int k1;
	int k2;

	i = 0;
	k = 1 + rand() % 63;
	k1 = 1 + rand() % 63;
	k2 = 1 + rand() % 63;
	while (i < 1000)
	{
		env->color[i].channel[0] = 255 / k * (i % k);
		env->color[i].channel[1] = 255 / k1 * (i % k1);
		env->color[i].channel[2] = 255 / k2 * (i % k2);
		i++;
	}
}

void	set_color_random2(t_env *env)
{
	int	i;
	int	k;

	i = 0;
	while (i < 1000)
	{
		k = rand() % 256;
		env->color[i].channel[0] = k;
		k = 1 + rand() % 256;
		env->color[i].channel[1] = k;
		k = 1 + rand() % 256;
		env->color[i].channel[2] = k;
		i++;
	}
}
