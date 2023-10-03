/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:26:34 by snocita           #+#    #+#             */
/*   Updated: 2023/03/22 14:26:49 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

/**
 * @brief  Finding the no of iterations for mandlebrot

 */
void	mandelbrot(t_mlx *mlx)
{
	t_oper	z;

	z = complex_init(mlx->c.r, mlx->c.i);
	mlx->iter = 0;
	while (pow(z.r, 2) + pow(z.i, 2) <= 4 && mlx->iter < mlx->iter_max)
	{
		z = complex_init(pow(z.r, 2) - pow(z.i, 2) + mlx->c.r, \
			2 * z.r * z.i + mlx->c.i);
		mlx->iter++;
	}
}

void	julia(t_mlx *mlx)
{
	t_oper	z;

	z = complex_init(mlx->c.r, mlx->c.i);
	mlx->iter = 0;
	while (pow(z.r, 2.0) + pow(z.i, 2.0) <= 4
		&& mlx->iter < mlx->iter_max)
	{
		z = complex_init(pow(z.r, 2.0) - pow(z.i, 2.0) + mlx->k.r, \
		2.0 * z.r * z.i + mlx->k.i);
		mlx->iter++;
	}
}

void	burning_ship(t_mlx *mlx)
{
	t_oper	z;

	z = complex_init(mlx->c.r, mlx->c.i);
	mlx->iter = 0;
	while (pow(z.r, 2.0) + pow(z.i, 2.0) <= 4 && \
				mlx->iter < mlx->iter_max)
	{
		z = complex_init(pow(z.r, 2.0) - pow(z.i, 2.0) + \
			(mlx->c.r), -2.0 * fabs(z.r * z.i) + mlx->c.i);
		mlx->iter++;
	}
}
