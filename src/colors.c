/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:25:45 by snocita           #+#    #+#             */
/*   Updated: 2023/04/22 16:43:51 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief The format adopted is the ARGB;
 * This function uses bitwise operators to pack 
 * the color components into a single integer value.
**/
int	trgb_gen(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	recode_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->img->data_addr + (y * mlx->img->line_size)
		+ x * (mlx->img->bpp / 8);
	*(unsigned int *)dest = color;
}

/**
 * @brief Returns an integer value representing a color to be used for a pixel
**/
int	color_init(t_mlx *mlx)
{
	double	t;
	int		color[4];

	t = (double)mlx->iter / (double)mlx->iter_max;
	color[0] = 0;
	if (mlx->shift == 1)
	{
		color[1] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[2] = (int)(14 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[3] = (int)(8.5 * pow((1 - t), 3) * t * 225);
	}
	if (mlx->shift == 2)
	{
		color[2] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[1] = (int)(13 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[3] = (int)(7 * pow((1 - t), 3) * t * 225);
	}
	if (mlx->shift == 3)
	{
		color[3] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[2] = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[1] = (int)(8.5 * pow((1 - t), 3) * t * 225);
	}
	return (trgb_gen(color[0], color[1], color[2], color[3]));
}
