/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:15:02 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 18:09:44 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractal.h"
#include "libft/libft.h"
#include "stdlib.h"

static int	init_env(t_env *env)
{
	if (!(env->mlx_ptr = mlx_init()))
		return (0);
	env->win = mlx_new_window(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test");
	if (!(env->win))
		return (0);
	(env->img).img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!((env->img).img_ptr))
	{
		mlx_destroy_window(env->mlx_ptr, env->win);
		return (0);
	}
	env->img.data = (int*)mlx_get_data_addr(env->img.img_ptr, &(env->img.bpp),
			&(env->img.size_l), &(env->img.endian));
	return (1);
}

void		close_all(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, (env->img).img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win);
	exit(0);
}

int			destroy_create_image(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, (env->img).img_ptr);
	mlx_clear_window(env->mlx_ptr, env->win);
	(env->img).img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!((env->img).img_ptr))
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		ft_putstr("usage : julia, mandelbrot, burning_ship, celtic_mandelbrot");
		ft_putstr(", phoenix, tricorn, queen, cross\n");
	}
	if (argc == 2)
	{
		if (!choose_fract(&env, argv[1]))
			return (0);
		if (!init_env(&env))
			return (0);
		env.fract_setup(&env);
		launch(&env);
		event(&env);
	}
	return (1);
}
