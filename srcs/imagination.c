/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:12:58 by rejocic           #+#    #+#             */
/*   Updated: 2018/11/13 11:13:00 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void		ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int				j;
	unsigned int	colorval;

	colorval = mlx_get_color_value(mlx->mlx_ptr, color);
	j = 0;
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	while (j < (mlx->bpp / 8))
	{
		*(mlx->addr + (mlx->lsize * y + ((mlx->bpp * x) / 8) + j)) = \
		(colorval >> (8 * j)) & 0xff;
		j++;
	}
}

int			ft_image(t_mlx *mlx)
{
	int			i;
	pthread_t	tid[8];
	t_threads	multithread[8];

	ft_memcpy(multithread, (t_threads[])\
	{&mf1, &mf2, &mf3, &mf4, &mf5, &mf6, &mf7, &mf8}, sizeof(t_threads) * 8);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp), \
	&(mlx->lsize), &(mlx->endian));
	i = -1;
	while (++i < 8)
		pthread_create(&tid[i], NULL, multithread[i], mlx);
	i = 0;
	while (i < 8)
		pthread_join(tid[i++], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	return (0);
}
