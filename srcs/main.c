/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:57:02 by rejocic           #+#    #+#             */
/*   Updated: 2018/11/12 09:47:00 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int			shut(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}

void		window(t_mlx *mlx)
{
	mlx->cords.cx = -0.835;
	mlx->cords.cy = 0.2321;
	mlx->comms.zoom = 1;
	mlx->comms.r = 1;
	mlx->comms.g = 1;
	mlx->comms.b = 1;
	mlx->cords.h = 1.5;
	mlx->cords.v = 1;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Sichuan");
	ft_image(mlx);
	mlx_hook(mlx->win_ptr, 17, 0, shut, mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 3, 0, key_release, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
	mlx_loop_hook(mlx->mlx_ptr, ft_image, mlx);
	mlx_loop(mlx->mlx_ptr);
}

void		whatfract(t_mlx *mlx, char **argv)
{
	if ((ft_strcmp(argv[1], "julia")) == 0)
		mlx->fractal = 0;
	else if ((ft_strcmp(argv[1], "mandelbrot")) == 0)
		mlx->fractal = 1;
	else if ((ft_strcmp(argv[1], "ship")) == 0)
		mlx->fractal = 2;
	window(mlx);
}

int			main(int argc, char **argv)
{
	t_mlx		*mlx;

	if (argc == 2)
	{
		mlx = (t_mlx *)malloc(sizeof(t_mlx));
		if ((ft_strcmp(argv[1], "julia")) == 0 || ft_strcmp(argv[1], \
		"mandelbrot") == 0 || ft_strcmp(argv[1], "ship") == 0)
			whatfract(mlx, argv);
		else
			ft_putstr("Please enter one of the following:\
			\njulia\nmandelbrot\nship\n");
		free(mlx);
	}
	if (argc > 2)
		ft_putstr("Too many input files, please enter only one at a time\n");
	else if (argc < 2)
		ft_putstr("No input given, please enter one of the following:\
		\njulia\nmandlebrot\nship\n");
	return (0);
}
