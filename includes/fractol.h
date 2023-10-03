/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:12:07 by snocita           #+#    #+#             */
/*   Updated: 2023/04/09 11:23:39 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "./keys.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"

/** Defining the parameters of the window **/

# define WIDTH 800
# define HEIGHT 600

# define MIN_V 1
# define MAX_V 100

/** 
 Struct for real and imaginary numbers **/
typedef struct s_oper
{
	double	r;
	double	i;
}		t_oper;

/** Struct to draw images **/

/**
 *	@brief Endian refers to the way in which a computer 
 *	stores multi-byte data types, such as integers, in memory. 
**/
typedef struct s_img
{
	void	*img;
	char	*data_addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_img;

/** Struct to calculate fractals **/

typedef struct s_mlx
{
	t_img			*img;
	void			*mlx;
	void			*win;
	int				iter;
	int				iter_max;
	int				press;
	int				shift;
	t_oper			max;
	t_oper			min;
	t_oper			c;
	t_oper			k;
	void			(*eqn)(struct s_mlx *);

}		t_mlx;

t_oper		complex_init(double r, double i);
t_img		*img_init(t_mlx *mlx);

void		default_init(t_mlx *mlx);
int			color_init(t_mlx *mlx);

int			trgb_gen(int t, int r, int g, int b);
void		recode_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
double		lerp(double start, double end, double inter_coeff);

int			ctrl_mouse(int key, int x, int y, t_mlx *mlx);
int			keymap(int key, t_mlx *mlx);

void		render_fractal(t_mlx *mlx);
void		mandelbrot(t_mlx *mlx);
void		julia(t_mlx *mlx);
void		burning_ship(t_mlx *mlx);

void		gui_init(t_mlx *mlx);

void		arg_check(char *arg);
void		help_options(void);

int			change_julia(int x, int y, t_mlx *mlx);
int			julia_key_press(int key, int x, int y, t_mlx *mlx);

void		move_w_key(int key, t_mlx *mlx);
void		shift_color(t_mlx *mlx);

int			close_window(t_mlx *mlx);

#endif
