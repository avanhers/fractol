/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:25:05 by avanhers          #+#    #+#             */
/*   Updated: 2019/05/10 18:00:42 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "libft/libft.h"

void	set_fract_fun(t_fract_f fract_fu[8])
{
	fract_fu[0] = &julia;
	fract_fu[1] = &mandelbrot;
	fract_fu[2] = &burning_ship;
	fract_fu[3] = &celtic_mandelbrot;
	fract_fu[4] = &phoenix;
	fract_fu[5] = &tricorn;
	fract_fu[6] = &queen;
	fract_fu[7] = &cross;
}

void	set_fract_set(t_fract_set fract_s[8])
{
	fract_s[0] = &setup_julia;
	fract_s[1] = &setup_mandelbrot;
	fract_s[2] = &setup_burning_ship;
	fract_s[3] = &setup_celtic_mandelbrot;
	fract_s[4] = &setup_phoenix;
	fract_s[5] = &setup_tricorn;
	fract_s[6] = &setup_queen;
	fract_s[7] = &setup_cross;
}

void	initialize(char *name_fract[8])
{
	name_fract[0] = "julia";
	name_fract[1] = "mandelbrot";
	name_fract[2] = "burning_ship";
	name_fract[3] = "celtic_mandelbrot";
	name_fract[4] = "phoenix";
	name_fract[5] = "tricorn";
	name_fract[6] = "queen";
	name_fract[7] = "cross";
}

int		choose_fract(t_env *env, char *name)
{
	static	t_fract_f		fun[8] = {NULL};
	static	t_fract_set		setup[8] = {NULL};
	char					*name_fract[8];
	int						i;

	initialize(name_fract);
	if (fun[0] == NULL)
		set_fract_fun(fun);
	if (setup[0] == NULL)
		set_fract_set(setup);
	i = 0;
	while (i < 8 && ft_strcmp(name_fract[i], name))
		i++;
	if (i < 8)
	{
		env->fract_fu = fun[i];
		env->fract_setup = setup[i];
	}
	else
	{
		ft_putstr("usage : julia, mandelbrot, burning_ship, celtic_mandelbrot");
		ft_putstr(", phoenix, tricorn, queen, cross\n");
		return (0);
	}
	return (1);
}
