/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:35:09 by rejocic           #+#    #+#             */
/*   Updated: 2018/11/12 10:35:10 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void		juliacalc(t_mlx *mlx, float x, float y)
{
	float			zx;
	float			zy;
	unsigned int	iter;

	zx = ((x / (WIDTH / 3)) - mlx->cords.h) / (0.8 * mlx->comms.zoom);
	zy = ((y / (HEIGHT / 2)) - mlx->cords.v) / (0.8 * mlx->comms.zoom);
	iter = 0;
	mlx->max_iter = 500;
	while ((zx * zx) + (zy * zy) < 4 && iter < mlx->max_iter)
	{
		mlx->cords.tmpx = (zx * zx) - (zy * zy);
		zy = (2 * zx * zy) + mlx->cords.cy;
		zx = mlx->cords.tmpx + mlx->cords.cx;
		iter++;
	}
	if (iter == mlx->max_iter)
		ft_put_pixel(mlx, x, y, 0x000000);
	else
		ft_put_pixel(mlx, x, y, ((((mlx->comms.r * iter) % 256) * 256 + \
		((mlx->comms.g * iter) % 256)) * 256 + (mlx->comms.b * iter) % 256));
}

void		mandelcalc(t_mlx *mlx, float x, float y)
{
	float			zx;
	float			zy;
	float			px;
	float			py;
	unsigned int	iter;

	zx = ((x / (WIDTH / 3)) - (mlx->cords.h + 0.7)) / (0.8 * mlx->comms.zoom);
	zy = ((y / (HEIGHT / 2)) - mlx->cords.v) / (0.8 * mlx->comms.zoom);
	px = 0.0;
	py = 0.0;
	iter = 0;
	mlx->max_iter = 500;
	while ((px * px) + (py * py) < 4 && iter < mlx->max_iter)
	{
		mlx->cords.tmpx = (px * px) - (py * py) + zx;
		py = (2 * px * py) + zy;
		px = mlx->cords.tmpx;
		iter++;
	}
	if (iter == mlx->max_iter)
		ft_put_pixel(mlx, x, y, 0x000000);
	else
		ft_put_pixel(mlx, x, y, (((mlx->comms.r * iter % 256) * 256 + \
		(mlx->comms.g * iter % 256)) * 256 + mlx->comms.b * iter % 256));
}

void		shipcalc(t_mlx *mlx, float x, float y)
{
	float			zx;
	float			zy;
	float			px;
	float			py;
	unsigned int	iter;

	zx = ((x / (WIDTH / 3)) - (mlx->cords.h + 0.2)) / (0.6 * mlx->comms.zoom);
	zy = ((y / (HEIGHT / 1.5)) - mlx->cords.v) / (0.6 * mlx->comms.zoom);
	px = zx;
	py = zy;
	iter = 0;
	mlx->max_iter = 500;
	while ((px * px) + (py * py) < 4 && iter < mlx->max_iter)
	{
		mlx->cords.tmpx = (px * px) - (py * py) + zx;
		py = fabs(2 * px * py) + zy;
		px = fabs(mlx->cords.tmpx);
		iter++;
	}
	if (iter == mlx->max_iter)
		ft_put_pixel(mlx, x, y, 0x000000);
	else
		ft_put_pixel(mlx, x, y, (((mlx->comms.r * iter % 256) * 256 + \
		(mlx->comms.g * iter % 256)) * 256 + mlx->comms.b * iter % 256));
}

int			fractal(t_mlx *mlx, float y, float max_y)
{
	float	x;

	x = 0;
	while (y < max_y)
	{
		while (x < WIDTH)
		{
			if (mlx->fractal == 0)
				juliacalc(mlx, x, y);
			else if (mlx->fractal == 1)
				mandelcalc(mlx, x, y);
			else if (mlx->fractal == 2)
				shipcalc(mlx, x, y);
			else
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
