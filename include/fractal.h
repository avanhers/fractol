/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:43:45 by avanhers          #+#    #+#             */
/*   Updated: 2019/09/24 15:20:50 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <pthread.h>
# include "../libft/libft.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MAX_ITER 999
# define R 0
# define I 1
# define THREADS 8

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_pixel
{
	int		x;
	int		y;
}				t_pixel;

typedef	struct	s_value
{
	int			i;
	double		index;
}				t_value;

typedef	void	(*t_fract_f)(t_pixel pixel, void *env);
typedef	void	(*t_fract_set)(void *env);

typedef union	u_color
{
	unsigned int		number;
	unsigned char		channel[4];
}				t_color;

typedef	struct	s_env
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	int			max_iter;

	double		zoom;
	double		c[2];
	double		z[2];
	double		z2[2];
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		dx;
	double		dy;

	t_color		color[1000];
	t_fract_f	fract_fu;
	t_fract_set	fract_setup;
	char		name;
	int			lock;
	int			autozoom;
}				t_env;

typedef struct	s_args
{
	int			x;
	int			y;
	int			nt;
	t_env		*env;
	pthread_t	t;
}				t_args;

double			convert(int old, double min, double max, int lenght);
void			*draw(void *param);
void			draw_pixel(t_pixel pixel, t_env *env, int value);
int				launch(t_env *env);
void			close_all(t_env *env);

void			julia(t_pixel pixel, void *env);
void			mandelbrot(t_pixel pixel, void *env);
void			burning_ship(t_pixel pixel, void *env);
void			celtic_mandelbrot(t_pixel pixel, void *env);
void			phoenix(t_pixel pixel, void *env);
void			tricorn(t_pixel pixel, void *env);
void			queen(t_pixel pixel, void *env);
void			cross(t_pixel pixel, void *env);

void			set_fract_fun(t_fract_f fract_fun[10]);
void			set_fract_set(t_fract_set fract_setup[10]);

void			setup_julia(void *env);
void			setup_mandelbrot(void *env);
void			setup_celtic_mandelbrot(void *env);
void			setup_burning_ship(void *env);
void			setup_phoenix(void *env);
void			setup_tricorn(void *env);
void			setup_queen(void *env);
void			setup_cross(void *env);

void			set_color_mine(t_env *env);
void			set_color_black(t_env *env);
void			set_color_random(t_env *env);
void			set_color_random2(t_env *env);

void			zoom(int x, int y, double zoom, t_env *env);
int				mouse_press(int button, int x, int y, t_env *env);
int				mouse_move(int x, int y, t_env *env);
int				key_release(int keycode, t_env *env);
int				key_press(int key_code, t_env *env);
int				mouse_release(int button, int x, int y, t_env *env);

int				destroy_create_image(t_env *env);
int				event(t_env *env);
int				choose_fract(t_env *env, char *name);
#endif
