/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:50:38 by rejocic           #+#    #+#             */
/*   Updated: 2018/11/16 14:50:40 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int			key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 257)
		mlx->comms.shift = 1;
	if (keycode == 49)
	{
		mlx->cords.cx = -0.835;
		mlx->cords.cy = 0.2321;
	}
	if (keycode == 53 || keycode == 51)
		exit(0);
	if (keycode == 24)
		mlx->comms.zoom *= 1.1;
	if (keycode == 27)
		mlx->comms.zoom /= 1.1;
	if (keycode == 15)
		mlx->comms.r += 1;
	if (keycode == 5)
		mlx->comms.g += 1;
	if (keycode == 11)
		mlx->comms.b += 1;
	else
		key_press2(keycode, mlx);
	return (0);
}

int			key_press2(int keycode, t_mlx *mlx)
{
	if (keycode == 123 && mlx->comms.shift == 1)
		mlx->cords.h += 0.5;
	if (keycode == 124 && mlx->comms.shift == 1)
		mlx->cords.h -= 0.5;
	if (keycode == 125 && mlx->comms.shift == 1)
		mlx->cords.v -= 0.5;
	if (keycode == 126 && mlx->comms.shift == 1)
		mlx->cords.v += 0.5;
	if (keycode == 14)
		mlx->comms.r -= 1;
	if (keycode == 3)
		mlx->comms.g -= 1;
	if (keycode == 9)
		mlx->comms.b -= 1;
	if (keycode == 123)
		mlx->cords.h += 0.1;
	if (keycode == 124)
		mlx->cords.h -= 0.1;
	if (keycode == 125)
		mlx->cords.v -= 0.1;
	if (keycode == 126)
		mlx->cords.v += 0.1;
	return (0);
}

int			key_release(int keycode, t_mlx *mlx)
{
	if (keycode == 257)
		mlx->comms.shift = 0;
	return (0);
}

int			mouse_move(int x, int y, t_mlx *mlx)
{
	double	dx;
	double	dy;

	dx = x;
	dy = y;
	dx -= WIDTH / 2;
	dy -= HEIGHT / 2;
	mlx->cords.cx = -0.835 + dx / (WIDTH / 2);
	mlx->cords.cy = 0.2321 + dy / (HEIGHT / 2);
	return (0);
}

int			mouse_press(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 4)
		mlx->comms.zoom /= 1.1;
	if (button == 5)
		mlx->comms.zoom *= 1.1;
	return (0);
}
