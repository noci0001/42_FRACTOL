/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:28:06 by snocita           #+#    #+#             */
/*   Updated: 2023/10/03 10:08:21 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

void	render_fractal(t_mlx *mlx)
{
	int		x;
	int		y;
	t_oper	scale;

	scale = complex_init((mlx->max.r - mlx->min.r) \
		/ (WIDTH), (mlx->max.i - mlx->min.i) / (HEIGHT));
	y = 0;
	while (y < HEIGHT)
	{
		mlx->c.i = mlx->max.i - y * scale.i;
		x = 0;
		while (x < WIDTH)
		{
			mlx->c.r = mlx->min.r + x * scale.r;
			mlx->eqn(mlx);
			recode_mlx_pixel_put(mlx, x, y, color_init(mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

void	help_options(void)
{
	ft_putendl_fd("EXPECTED INPUT:", 1);
	ft_putendl_fd("\t./fractol <no>", 1);
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("Available fractals:\n", 1);
	ft_putendl_fd("\tM\t1\tMandelbrot\n", 1);
	ft_putendl_fd("\tJ\t2\tJulia\n", 1);
	ft_putendl_fd("\tB\t3\tBurningship\n", 1);
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("Mouse:", 1);
	ft_putendl_fd("\tZoom with scrollWheel", 1);
	ft_putendl_fd("Keys:", 1);
	ft_putendl_fd("\tWASD keys to move", 1);
	ft_putendl_fd("\tQ and E to increase or decrease iterations", 1);
	ft_putendl_fd("\tC to shift colors", 1);
	ft_putendl_fd("\tPress SPACE to reset fractol", 1);
	ft_putendl_fd("\tPress ESC to exit the program", 1);
	ft_putendl_fd("ENJOY!", 1);
}

void	gui_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, \
		"FrAct-ol");
	mlx->img = img_init(mlx);
	default_init(mlx);
	mlx_hook(mlx->win, 2, 0, keymap, mlx);
	mlx_hook(mlx->win, 4, 0, ctrl_mouse, mlx);
	if (mlx->eqn == &mandelbrot)
		mlx_hook(mlx->win, 17, 0, close_window, mlx);
	if (mlx->eqn == &julia)
	{
		mlx_hook(mlx->win, 5, 0, julia_key_press, mlx);
		mlx_hook(mlx->win, 2, 0, keymap, mlx);
		mlx_hook(mlx->win, 6, 0, change_julia, mlx);
		mlx_hook(mlx->win, 17, 0, close_window, mlx);
	}
	render_fractal(mlx);
	mlx_loop(mlx->mlx);
}

void	arg_check(char *arg)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if ((!(ft_strncmp(arg, "1", 1))) || (!(ft_strncmp(arg, "M", 1)))
		|| (!(ft_strncmp(arg, "Mandelbrot", 10))))
	{
		mlx->eqn = &mandelbrot;
		gui_init(mlx);
	}
	else if ((!(ft_strncmp(arg, "2", 1))) || (!(ft_strncmp(arg, "J", 1)))
		|| (!(ft_strncmp(arg, "Julia", 5))))
	{
		mlx->eqn = &julia;
		gui_init(mlx);
	}
	else if ((!(ft_strncmp(arg, "3", 1))) || (!(ft_strncmp(arg, "B", 1)))
		|| (!(ft_strncmp(arg, "Burningship", 12))))
	{
		mlx->eqn = &burning_ship;
		gui_init(mlx);
	}
	free (mlx);
	help_options();
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		arg_check(argv[1]);
	else
		help_options();
	return (0);
}
