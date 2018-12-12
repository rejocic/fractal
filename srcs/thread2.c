/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:51:02 by rejocic           #+#    #+#             */
/*   Updated: 2018/11/27 11:51:03 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void		*mf5(void *param)
{
	int		y;
	int		max_y;
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	y = (HEIGHT / 8) * 4;
	max_y = (HEIGHT / 8) * 5;
	fractal(mlx, y, max_y);
	return (NULL);
}

void		*mf6(void *param)
{
	int		y;
	int		max_y;
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	y = (HEIGHT / 8) * 5;
	max_y = (HEIGHT / 8) * 6;
	fractal(mlx, y, max_y);
	return (NULL);
}

void		*mf7(void *param)
{
	int		y;
	int		max_y;
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	y = (HEIGHT / 8) * 6;
	max_y = (HEIGHT / 8) * 7;
	fractal(mlx, y, max_y);
	return (NULL);
}

void		*mf8(void *param)
{
	int		y;
	int		max_y;
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	y = (HEIGHT / 8) * 7;
	max_y = HEIGHT;
	fractal(mlx, y, max_y);
	return (NULL);
}
