/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:50:55 by rejocic           #+#    #+#             */
/*   Updated: 2018/11/27 11:50:57 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void		*mf1(void *param)
{
	int		y;
	int		max_y;
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	y = 0;
	max_y = HEIGHT / 8;
	fractal(mlx, y, max_y);
	return (NULL);
}

void		*mf2(void *param)
{
	int		y;
	int		max_y;
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	y = HEIGHT / 8;
	max_y = (HEIGHT / 8) * 2;
	fractal(mlx, y, max_y);
	return (NULL);
}

void		*mf3(void *param)
{
	int		y;
	int		max_y;
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	y = (HEIGHT / 8) * 2;
	max_y = (HEIGHT / 8) * 3;
	fractal(mlx, y, max_y);
	return (NULL);
}

void		*mf4(void *param)
{
	int		y;
	int		max_y;
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	y = (HEIGHT / 8) * 3;
	max_y = (HEIGHT / 8) * 4;
	fractal(mlx, y, max_y);
	return (NULL);
}
